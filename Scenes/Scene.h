#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <string>

#include "../Lights/Light.h"
#include "../Cameras/Camera.h"
#include "../Objects/Object.h"


class Scene
{
    public:
        Scene() {}

        virtual ~Scene();

        void addObject(Object* obj)
        {
            objects.push_back(obj);
        }

        void render(std::string fileName) const;

    protected:
        Camera* cam;
        Light* light;
        std::vector<Object*> objects;
        std::vector<Material*> mats;
};

#endif // SCENE_H
