#include "SphereScene.h"

#include "../Objects/Sphere.h"
#include "../Cameras/PerspectiveCamera.h"
#include "../Cameras/OrthographicCamera.h"
#include "../Lights/PointLight.h"
#include "../Materials/PlainColorMaterial.h"
#include "../Materials/DiffuseMaterial.h"

SphereScene::SphereScene()
{
    int focalRatio = 1;
    int wh = 600;
    cam = new OrthographicCamera(wh, wh, {0, 0, -600});

    mats.push_back(new DiffuseMaterial({1, 0, 0}, {1}, {.1}));

    objects.push_back(new Sphere(mats[0], 100, {0, 0, 0}));

    float offset = 100;
    light = new PointLight({offset, offset, offset}, {1.}, 20000);
}

