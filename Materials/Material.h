#ifndef MATERIAL_H
#define MATERIAL_H

#include "../Lights/Light.h"
#include "../Utils/Ray.h"
#include "../Utils/IntersectionData.h"

class Scene;

class Material
{

    public:
        Material() = default;

        virtual ~Material() = default;

        virtual Color getColor(const Ray* ray,
                               const IntersectionData* dat,
                               const Scene* scene,
                               int depth) const = 0;
};

#endif // MATERIAL_H
