#include <iostream>
#include <assert.h>
#include <vector>
#include <climits>

#include "Sphere.h"
#include "Object.h"
#include "Plane.h"
#include "Utils/IntersectionData.h"
#include "Image.h"
#include "PointLight.h"

double clamp(double v, double min, double max) { return v < max ? v < min ? min : v : max; }

int main()
{
    size_t W(800), H(800);

    Image img(W, H);

    Material mat({1, 0, 0}, {1}, {.1, 0, 0});
    Material mat2({1, 1, 0}, {1}, {.1});

    std::vector<Object*> objects;
    objects.push_back(new Sphere(&mat, H/4., {0, 0, 0}));
    objects.push_back(new Sphere(&mat, H/3., {500, 0, (double)H}));

    objects.push_back(new Plane(&mat2, {0, 300, 0}, {0, -1, 0}));

    double offset = 1000;
    PointLight light({-offset, -offset, -offset}, {1.}, 2000000);


    double focalLength = 400;
    for(size_t y = 0; y < H; ++y)
    {
        for(size_t x = 0; x < W; ++x)
        {
            bool intersectedSomething = false;

            Vec4 dir(x - W/2.0, y - H/2.0, focalLength);
            dir = dir.normalized();
            Ray r({0, 0, -1000}, dir);
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
                img.setPixel(x, y, Color(0));
                continue;
            }

            Vec4 interToLight = light.pos - dat.pos;
            double dist = interToLight.mag();
            double distSq = dist * dist;
            Ray shadowRay({dat.pos}, interToLight.normalized());
            bool isShadow = false;

            Color finalColor = dat.mat->ambientColor;
            for(const auto& obj: objects)
            {
                if (obj->intersect(shadowRay, nullptr))
                {
                    isShadow = true;
                    break;
                }
            }
            if (!isShadow)
            {
                double cosTheta = clamp(interToLight.normalized().dot(dat.n), 0, 1);

                Vec4 R = interToLight.normalized().reflect(dat.n);
                double cosAlpha = clamp(dir.dot(R), 0, 1);

                Color commonPart = light.c * light.power / distSq;
                finalColor +=   dat.mat->diffuseColor * cosTheta * commonPart
                                + dat.mat->specularColor  * pow(cosAlpha, 5) * commonPart;
            }
            img.setPixel(x, y, (finalColor / 1).clamp());
        }
    }

    img.saveImage("img");
    return 0;
}
