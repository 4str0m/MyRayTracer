#include "ReflexiveMaterial.h"

#include "../Scenes/Scene.h"

Color ReflexiveMaterial::getColor(const Ray* ray, const IntersectionData* dat, const Scene* scene, int depth) const
{
    return  (m_diffusePart.getColor(ray, dat, scene, depth) * m_factor) +
            (scene->throwRay(Ray(dat->pos, reflect(ray->d, dat->n)), depth+1) * (1.0 - m_factor));
}
