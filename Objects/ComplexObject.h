#ifndef COMPLEXOBJECT_H
#define COMPLEXOBJECT_H

#include <Object.h>
#include <vector>
#include "../Utils/Vertex.h"
#include "../Utils/Texture.h"

class ComplexObject final : public Object
{
public:
    struct Triangle
    {
        struct Vertex
        {
            unsigned int p, n, uv, c;

            Vertex(unsigned int p, unsigned int n, unsigned int uv, unsigned int c)
            : p(p), n(n), uv(uv), c(c) {}
        };
        Vertex v0;
        Vertex v1;
        Vertex v2;

        Triangle(const Vertex& v0, const Vertex& v1, const Vertex& v2)
        :   v0(v0)
        ,   v1(v1)
        ,   v2(v2)
        {}
    };

    public:
        static ComplexObject* loadFromFile(Material *mat, const std::string& fileName);

        bool intersect(const Ray& ray, IntersectionData *intersectionData) const override;

        ComplexObject(Material *mat, std::vector<Vector3f> positions, std::vector<Vector3f> normals,
                        std::vector<Vector2f> uvs, std::vector<Color> colors, std::vector<Triangle>& triangles,
                        Texture *tex = nullptr)
        :   Object(mat)
        ,   m_positions (std::move(positions))
        ,   m_normals   (std::move(normals))
        ,   m_uvs       (std::move(uvs))
        ,   m_colors    (std::move(colors))
        ,   m_triangles (std::move(triangles))
        ,   m_tex(tex) {}

    private:
        bool intersectTriangle(const Triangle& triangle, const Ray& ray, IntersectionData *intersectionData) const;

    private:
        std::vector<Vector3f> m_positions;
        std::vector<Vector3f> m_normals;
        std::vector<Vector2f> m_uvs;
        std::vector<Color> m_colors;
        std::vector<Triangle> m_triangles;
        Texture* m_tex;
};

ComplexObject* createCube(Material* mat, float sideLength = 50, Texture* tex = nullptr);

#endif // COMPLEXOBJECT_H
