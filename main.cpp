#include <iostream>

#include "Sphere.h"
#include "Utils/IntersectionData.h"
#include "Image.h"

#include <assert.h>

#define ANTI_ALIAZING_FACTOR 1.0/2.0

int main()
{
    size_t W(100), H(100);

    Image img(W, H);

    Sphere s(H/3, {W/2, H/2, 0});

    Vec4 dir(0, 0, 1);
    IntersectionData dat;

    Vec4 light(W/3, H/3, -50);

    for(size_t y = 0; y < H; ++y)
    {
        for(size_t x = 0; x < W; ++x)
        {
            float gray(0);
            size_t numberOfDivs = 0;
            for(double dy = y; dy < y+1; dy += ANTI_ALIAZING_FACTOR)
            {
                for(double dx = x; dx < x+1; dx += ANTI_ALIAZING_FACTOR)
                {
                    Ray r({dx, dy, -100}, dir);
                    if (s.intersect(r, &dat))
                    {
                        Vec4 interToLight = (light - dat.pos).normalized();
                        double dot = interToLight.dot(dat.normal);
                        gray += dot < 0 ? 0 : dot;
                    }
                    ++numberOfDivs;
                }
            }
            img.setPixel(x, y, (s.m_mat.c * gray/numberOfDivs));
        }
    }

    img.saveImage("img");
    return 0;
}
