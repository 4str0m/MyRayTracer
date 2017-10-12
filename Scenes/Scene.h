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

    private:
        Color throwRay(const Ray& ray, size_t depth) const;

    protected:
        Camera* cam;
        Light* light;
        std::vector<Object*> objects;
        std::vector<Material*> mats;
};

#endif // SCENE_H
