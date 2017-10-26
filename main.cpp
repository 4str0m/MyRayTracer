#include <iostream>

#include "Scenes/Scene.h"
#include "Scenes/BasicScene.h"
#include "Scenes/SceneLoader.h"

#include "Utils/Texture.h"

/**
  * Render time for 1024x1024 -> 16 minutes
**/

int main()
{

    BasicScene scene;
    scene.render("OpenMPWithLoadingBar");
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
