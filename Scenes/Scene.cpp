#include "Scene.h"

#include <climits>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "../Utils/Image.h"

#define ANTI_ALIASING_FACTOR 2

void printProgress(double percent)
{
    system("cls");
    int numberOFBars = (int)(percent * 10);
    std::string progressBar(std::string(numberOFBars, '-') + std::string(10-numberOFBars, ' '));
    printf("Rendering progress : [");
    std::cout << progressBar;
    printf("] %05.2f%%\n", percent * 100.0);
}

Scene::~Scene()
{
    delete cam;
    delete light;
    for(size_t i = 0; i < objects.size(); ++i)
        delete objects[i];

    for(size_t i = 0; i < mats.size(); ++i)
        delete mats[i];
}

void Scene::render(std::string fileName) const
{
    Image img(cam->getWidth(), cam->getHeight());

    for(size_t y = 0; y < cam->getHeight(); ++y)
    {
        for(size_t x = 0; x < cam->getWidth(); ++x)
        {
            Color finalColor;
            for(double dy = 0.; dy < 1.; dy += 1. / ANTI_ALIASING_FACTOR)
            {
                for(double dx = 0.; dx < 1.; dx += 1. / ANTI_ALIASING_FACTOR)
                {
                    Ray r = cam->getRayAtPixel(x+dx, y+dy);
                    finalColor += throwRay(r, 1);
                }
            }

            img.setPixel(x, y, (finalColor / ANTI_ALIASING_FACTOR / ANTI_ALIASING_FACTOR).clamp());
        }
        printProgress((double)y / cam->getHeight());
    }

    img.saveImage(fileName);
}

Color Scene::throwRay(const Ray& ray, size_t depth) const
{
    if (depth > 5)
        return Color::BLACK;

    bool intersectedSomething = false;
    IntersectionData dat;
    dat.d = INT_MAX;
    for(const auto& obj: objects)
    {
        IntersectionData temp;
        if (obj->intersect(ray, &temp) && temp.d < dat.d)
        {
            intersectedSomething = true;
            dat = temp;
        }
    }
    if (!intersectedSomething)
    {
        return Color::LIGHT_BLUE;
    }

    switch (dat.mat->getType())
    {
    case MaterialType::PLAIN:
        return dat.mat->getColor(ray, dat, light, false);

    case MaterialType::DIFFUSE:
    {
        Vector3d interToLight = light->pos - dat.pos;
        Ray shadowRay(dat.pos, interToLight.normalized());
        bool isShadow = false;
        for(const auto& obj: objects)
        {
            if (obj->intersect(shadowRay, nullptr))
            {
                isShadow = true;
                break;
            }
        }
        return dat.mat->getColor(ray, dat, light, isShadow);
    }
    case MaterialType::REFLEXIVE:
        return throwRay(Ray(dat.pos, reflect(ray.d, dat.n)), depth+1);
    }
    return Color::BLACK;
}
