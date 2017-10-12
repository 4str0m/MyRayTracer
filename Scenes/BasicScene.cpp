#include "BasicScene.h"

#include "../Objects/Sphere.h"
#include "../Objects/Plane.h"
#include "../Objects/Triangle.h"
#include "../Objects/ComplexObject.h"
#include "../Cameras/PerspectiveCamera.h"
#include "../Lights/PointLight.h"
#include "../Materials/PlainColorMaterial.h"
#include "../Materials/DiffuseMaterial.h"

BasicScene::BasicScene()
{
    int focalRatio = 1;
    int wh = 200;
    cam = new PerspectiveCamera(wh, wh, {0, 50, -100}, wh*focalRatio);

    mats.push_back(new DiffuseMaterial({1, 0, 0}, {1}, {.1}));
    mats.push_back(new DiffuseMaterial({0, 1, 0}, {1}, {.1}));
    mats.push_back(new DiffuseMaterial({0, 0, 0}, {.2}, {.1}, 2));

    //objects.push_back(new Triangle(mats[0], {}, {-400, 0, 0}, {0, 400, 0}));

    Object *cube = ComplexObject::loadFromFile(mats[0], "cube.obj");
    cube->rotate(45, Vector3d::UnitY());
    objects.push_back(cube);

    double sphereRadius = 10;
    Sphere *s = new Sphere(mats[0], sphereRadius, {0, sphereRadius, 0});
    s->translate({0, 10, 0});
    objects.push_back(s);
    objects.push_back(new Sphere(mats[2], sphereRadius, {sphereRadius*2, sphereRadius, 0}));

    objects.push_back(new Plane(mats[1], {0, 0, 0}, {0, 1, 0}));

    double offset = 100;
    light = new PointLight({offset, offset, offset}, {1.}, 20000);
}
