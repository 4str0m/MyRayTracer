#include "ReflexiveMaterial.h"

Color ReflexiveMaterial::getColor(const Ray& ray, const IntersectionData& dat, const Light* light, bool isInShadow) const
{
    return Color::BLACK;
}
