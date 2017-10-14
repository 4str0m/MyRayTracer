#ifndef SCENELOADER_H
#define SCENELOADER_H

#include "Scene.h"

class SceneLoader
{
    public:
        static bool loadSceneFromFile(const std::string& fileName, Scene &scene);

    private:
        static bool loadCameraFromString    (const std::string& line, Scene &scene);
        static bool loadMaterialFromString  (const std::string& line, Scene &scene);
        static bool loadLightFromString     (const std::string& line, Scene &scene);
        static bool loadSphereFromString    (const std::string& line, Scene &scene);
        static bool loadColorFromString     (const std::string& line, Color &color);
        static bool loadVectorFromString    (const std::string& line, Vector3f &point);
};

#endif // SCENELOADER_H
