#include "Scene.h"

#include <climits>
#include "../Utils/Image.h"

#define ANTI_ALIASING_FACTOR 2

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
                    bool intersectedSomething = false;

                    Ray r = cam->getRayAtPixel(x+dx, y+dy);
                    IntersectionData dat;
                    dat.d = INT_MAX;
                    for(const auto& obj: objects)
                    {
                        IntersectionData temp;
                        if (obj->intersect(r, &temp) && temp.d < dat.d)
                        {
                            intersectedSomething = true;
                            dat = temp;
                        }
                    }
                    if (!intersectedSomething)
                    {
                        img.setPixel(x, y, Color::BLACK);
                        continue;
                    }


                    Vector3d interToLight = light->pos - dat.pos;
                    Ray shadowRay({dat.pos}, interToLight.normalized());
                    bool isShadow = false;
                    for(const auto& obj: objects)
                    {
                        if (obj->intersect(shadowRay, nullptr))
                        {
                            isShadow = true;
                            break;
                        }
                    }
                    finalColor += dat.mat->getColor(r, dat, light, isShadow);

                }
            }

            img.setPixel(x, y, (finalColor / ANTI_ALIASING_FACTOR / ANTI_ALIASING_FACTOR).clamp());
        }
        std::cout << "Completed : " << 100.0 * y / cam->getHeight()<< "% of rendreing..." << std::endl;
    }

    img.saveImage(fileName);
}
