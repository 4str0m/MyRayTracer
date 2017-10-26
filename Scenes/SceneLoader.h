#ifndef SCENELOADER_H
#define SCENELOADER_H

#include "Scene.h"

class SceneLoader
{
    public:
        static bool loadSceneFromFile(const std::string& fileName, Scene &scene);

    private:
        static bool loadColorFromString     (const std::string& line, Color &color);
        static bool loadVectorFromString    (const std::string& line, Vector3f &point);
        static bool loadNameFromString      (const std::string& line, std::string &name);
};

#endif // SCENELOADER_H
