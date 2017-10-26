#include <iostream>

#include "Scenes/Scene.h"
#include "Scenes/BasicScene.h"
#include "Scenes/SceneLoader.h"

#include "Utils/Texture.h"

int main()
{

    BasicScene scene;
    scene.render("testWithoutTexture");
//
//    if (SceneLoader::loadSceneFromFile("sample_scene.txt", scene))
//    {
//        scene.render("testPerformance");
//    }
//    else
//    {
//        std::cout << "unable to load scene" << std::endl;
//    }
    return 0;
}
