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
    cam = new PerspectiveCamera(wh, wh, {100, 80, -150}, wh*focalRatio);

    addMaterial(new DiffuseMaterial("", {1, 0, 0}, {1}, .2));
    addMaterial(new DiffuseMaterial("", {0, 1, 0}, {1}, .2));
    addMaterial(new DiffuseMaterial("", {.5, .5, .5}, {.2}, .1, 2));
    addMaterial(new ReflexiveMaterial("", {.1, .5, .3}, {1}, .2, 10, .5));

    addTexture(new Texture("res/box.jpg"));

    addObject(createCube(mats[0], 50, texs[0]));

    //Object *cube = ComplexObject::loadFromFile(mats[0], "cube.obj");
    //cube->rotate(0, Vector3f::UnitY());
    //objects.push_back(cube);

    float sphereRadius = 15;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if (i*j == 1)
                addObject(new Sphere(mats[3], sphereRadius*2, {sphereRadius*3*i + 20, sphereRadius*2-25, sphereRadius*3*j+40}));
            else
                addObject(new Sphere(mats[1], sphereRadius, {sphereRadius*3*i + 20, sphereRadius-25, sphereRadius*3*j+40}));
        }
    }

    addObject(new Plane(mats[2], {0, -25, 0}, {0, 1, 0}));

    float offset = 100;
    light = new PointLight({offset, 2*offset, offset/2}, {1.}, 20000);
}
