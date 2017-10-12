#include "DiffuseMaterial.h"

#include "../Utils/MyMath.h"

Color DiffuseMaterial::getColor(const Ray& ray, const IntersectionData& dat, const Light* light, bool isInShadow) const
{
    Color finalColor(m_ambientColor);

    if(isInShadow)
        return finalColor;

    Vec4 interToLight = light->pos - dat.pos;
    double dist = interToLight.mag();

    double cosTheta = std::clamp(interToLight.normalized().dot(dat.n), 0, 1);

    Vec4 R = interToLight.normalized().reflect(dat.n);
    double cosAlpha = std::clamp(ray.d.dot(R), 0, 1);

    Color commonPart = light->c * light->power / (dist * dist);
    finalColor +=   m_diffuseColor * cosTheta * commonPart
                    + m_specularColor  * pow(cosAlpha, m_specularPower) * commonPart;

    return finalColor;
}
