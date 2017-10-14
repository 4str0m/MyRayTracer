#include "BasicScene.h"

#include "../Objects/Sphere.h"
#include "../Objects/Plane.h"
#include "../Objects/Triangle.h"
#include "../Objects/ComplexObject.h"
#include "../Cameras/PerspectiveCamera.h"
#include "../Lights/PointLight.h"
#include "../Materials/PlainColorMaterial.h"
#include "../Materials/DiffuseMaterial.h"
#include "../Materials/ReflexiveMaterial.h"

BasicScene::BasicScene()
{
    int focalRatio = 1;
    int wh = 128;
    cam = new PerspectiveCamera(wh, wh, {50, 50, -100}, wh*focalRatio);

//    mats.push_back(new DiffuseMaterial({1, 0, 0}, {1}, {.1}));
//    mats.push_back(new DiffuseMaterial({0, 1, 0}, {1}, {.1}));
//    mats.push_back(new DiffuseMaterial({0, 0, 0}, {.2}, {.1}, 2));
//    mats.push_back(new ReflexiveMaterial({0, .5, 1}, {1}, {.2}, 10, .2));

    //objects.push_back(new Triangle(mats[0], {}, {-400, 0, 0}, {0, 400, 0}));

    //Object *cube = ComplexObject::loadFromFile(mats[0], "cube.obj");
    //cube->rotate(0, Vector3f::UnitY());
    //objects.push_back(cube);

    float sphereRadius = 10;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if (i*j == 1)
                objects.push_back(new Sphere(mats[1], sphereRadius*2, {sphereRadius*3*i, sphereRadius*2, sphereRadius*3*j}));
            else
                objects.push_back(new Sphere(mats[2], sphereRadius, {sphereRadius*3*i, sphereRadius, sphereRadius*3*j}));
        }
    }

    objects.push_back(new Plane(mats[3], {0, 0, 0}, {0, 1, 0}));

    float offset = 100;
    light = new PointLight({offset, offset, offset}, {1.}, 20000);
}
