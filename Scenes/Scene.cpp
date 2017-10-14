#include "Scene.h"

#include <climits>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>

#include "../Utils/Timer.h"
#include "../Utils/Image.h"

#define ANTI_ALIASING_FACTOR 2

void printProgress(float percent)
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
    Timer::get().set_clock();

    Image img(cam->getWidth(), cam->getHeight());

    float antiAliasingRatio = 1. / ANTI_ALIASING_FACTOR;

    for(size_t y = 0; y < cam->getHeight(); ++y)
    {
        for(size_t x = 0; x < cam->getWidth(); ++x)
        {
            Color finalColor;
            for(float dy = 0.; dy < 1.; dy += antiAliasingRatio)
            {
                for(float dx = 0.; dx < 1.; dx += antiAliasingRatio)
                {

                    Ray r = cam->getRayAtPixel(x+dx, y+dy);
                    finalColor += throwRay(r, 1);
                }
            }

            img.setPixel(x, y, (finalColor * antiAliasingRatio * antiAliasingRatio).clamp());
        }
        printProgress((float)y / cam->getHeight());
    }
    std::cout << "Finished rendering image !! " << Timer::get().elapsed_time() << std::endl;
    img.saveImage(fileName);
    std::cout << "Finished saving image !!" << std::endl;
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

    return dat.mat->getColor(&ray, &dat, this, depth);
}
