#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <string>

#include "../Lights/Light.h"
#include "../Cameras/Camera.h"
#include "../Objects/Object.h"
#include "../Utils/Texture.h"


class Scene
{
    public:
        Scene() = default;

        virtual ~Scene();

        Scene& addObject(Object* obj)
        {
            if (obj) objects.push_back(obj);
            return *this;
        }

        Scene& addLight(Light* l)
        {
            if (l) light = l;
            return *this;
        }

        Scene& addMaterial(Material* mat)
        {
            if (mat) mats.push_back(mat);
            return *this;
        }
        Scene& addTexture(Texture* tex)
        {
            if (tex) texs.push_back(tex);
            return *this;
        }

        void render(std::string fileName) const;

        Color throwRay(const Ray& ray, size_t depth) const;

        const Light* getLight() const { return light; }
        const std::vector<Object*>& getObjects() const { return objects; }

        const Material* getMaterialByName(const std::string& name) const;

    protected:
        Camera* cam = nullptr;
        Light* light = nullptr;
        std::vector<Object*> objects;
        std::vector<Material*> mats;
        std::vector<Texture*> texs;
};

#endif // SCENE_H
