#include "DiffuseMaterial.h"

#include "../Utils/MyMath.h"

Vector3d reflect(const Vector3d& v1, const Vector3d& v2)
{
    return v1 - 2 * v2 * v1.dot(v2);
}

Color DiffuseMaterial::getColor(const Ray& ray, const IntersectionData& dat, const Light* light, bool isInShadow) const
{
    Color finalColor(m_ambientColor);

    if(isInShadow)
        return finalColor;

    Vector3d interToLight = light->pos - dat.pos;
    double dist = interToLight.norm();

    double cosTheta = std::clamp(interToLight.normalized().dot(dat.n), 0, 1);

    Vector3d R = reflect(interToLight.normalized(), dat.n);
    double cosAlpha = std::clamp(ray.d.dot(R), 0, 1);

    Color commonPart = light->c * light->power / (dist * dist);
    finalColor +=   m_diffuseColor * cosTheta * commonPart
                    + m_specularColor  * pow(cosAlpha, m_specularPower) * commonPart;

    return finalColor;
}
