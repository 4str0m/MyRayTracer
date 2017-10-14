#include <iostream>

#include "Scenes/Scene.h"
#include "Scenes/SceneLoader.h"

int main()
{
    Scene scene;
    if (SceneLoader::loadSceneFromFile("sample_scene.txt", scene))
    {
        scene.render("testPerformance");
    }
    else
    {
        std::cout << "unable to load scene" << std::endl;
    }
    return 0;
}
