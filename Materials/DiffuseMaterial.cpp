#include "DiffuseMaterial.h"

#include "../Utils/MyMath.h"
#include "../Scenes/Scene.h"

Color DiffuseMaterial::getColor(const Ray* ray, const IntersectionData* dat, const Scene* scene, int depth) const
{

    Vector3f interToLight = scene->getLight()->pos - dat->pos;
    Ray shadowRay(dat->pos, interToLight.normalized());
    bool isInShadow = false;
    for(const auto& obj: scene->getObjects())
    {
        if (obj->intersect(shadowRay, nullptr))
        {
            isInShadow = true;
            break;
        }
    }

    Color diffuseColor = m_diffuseColor * dat->blendFactor + dat->c * (1-dat->blendFactor);
    Color finalColor(diffuseColor * m_ambientFactor);

    if(isInShadow)
        return finalColor;

    float dist = interToLight.norm();
    float cosTheta = std::clamp(interToLight.normalized().dot(dat->n), 0, 1);

    Vector3f R = reflect(interToLight.normalized(), dat->n);
    float cosAlpha = std::clamp(ray->d.dot(R), 0, 1);

    Color commonPart = scene->getLight()->c * scene->getLight()->power / (dist * dist);
    finalColor +=   diffuseColor * cosTheta * commonPart
                    + m_specularColor  * pow(cosAlpha, m_specularPower) * commonPart;

    return finalColor;
}
