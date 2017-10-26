#include "ComplexObject.h"

#include <iostream>
#include <fstream>
#include <string>

#include <cstdlib>
#include <Eigen/StdVector>

// TODO: modify with current implementation of Vertex
/*
ComplexObject* ComplexObject::loadFromFile(Material *mat, const std::string& fileName)
{
    std::vector<Vector3f, aligned_allocator<Vector3f>> vertices;
    std::vector<Vector3f, aligned_allocator<Vector3f>> normals;
    std::vector<Triangle*> triangles;

    std::ifstream file;
    std::string line;
    file.open(fileName);

    if (file.is_open())
    {
        while(getline(file, line))
        {
            // reading vertex
            if (line[0] == 'v' && line[1] == ' ')
            {
                char* endptr = nullptr;
                float x = strtod(line.c_str() + 2, &endptr);
                float y = strtod(endptr, &endptr);
                float z = strtod(endptr, &endptr);
                vertices.push_back(Vector3f(x, y, z) * 10);
            }
            else if (line[0] == 'v' && line[1] == 'n')
            {
                char* endptr = nullptr;
                float x = strtod(line.c_str() + 2, &endptr);
                float y = strtod(endptr, &endptr);
                float z = strtod(endptr, &endptr);
                normals.push_back(Vector3f(x, y, z) * 10);
            }
            else if (line[0] == 'f' && line[1] == ' ')
            {
                char* endptr = nullptr;
                unsigned long int vertId1 = strtoul(line.c_str()+2, &endptr, 10) - 1;
                while(*endptr != ' ') ++endptr;
                unsigned long int vertId2 = strtoul(endptr, &endptr, 10) - 1;
                while(*endptr != ' ') ++endptr;
                unsigned long int vertId3 = strtoul(endptr, &endptr, 10) - 1;
                triangles.push_back(new Triangle(nullptr, vertices[vertId1], vertices[vertId2], vertices[vertId3]));
            }
        }
        file.close();
    }
    return new ComplexObject(mat, triangles);
}
*/

bool ComplexObject::intersect(const Ray& ray, IntersectionData *intersectionData) const
{
    bool hasIntersected = false;
    IntersectionData temp;
    IntersectionData best;
    best.d = INT_MAX;
    for(const Triangle& triangle: m_triangles)
    {
        if (intersectTriangle(triangle, ray, &temp))
        {
            hasIntersected = true;
            if (!intersectionData)
                return true;
            if (temp.d < best.d)
            {
                best = temp;
            }
        }
    }
    if (!hasIntersected)
        return false;

    if (intersectionData)
    {
        *intersectionData = best;
        intersectionData->mat = m_mat;
    }
    return true;
}

bool ComplexObject::intersectTriangle(const Triangle& triangle, const Ray& ray, IntersectionData *intersectionData) const
{
    const Vector3f &p0 = m_positions[triangle.v0.p];
    const Vector3f &p1 = m_positions[triangle.v1.p];
    const Vector3f &p2 = m_positions[triangle.v2.p];
    Vector3f n = (p1-p0).cross(p2-p0).normalized();
    /* first compute intersection with plane containing triangle */
    float denom = ray.d.dot(n);
    if (denom == 0)
        return false;
    float d = (p0 - ray.o).dot(n) / denom;
    if (d < DELTA_INTERSECT)
        return false;

    Vector3f u = p1 - p0;
    Vector3f v = p2 - p0;

    Vector3f w = ray.at(d) - p0;

    float uv = u.dot(v);
    float wv = w.dot(v);
    float wu = w.dot(u);
    float vv = v.dot(v);
    float uu = u.dot(u);

    float denom2 = uv*uv - uu*vv;

    float s1 = (uv*wv - vv*wu) / denom2;
    float t1 = (uv*wu - uu*wv) / denom2;

    // check if point in triangle
    if (s1 < 0 || t1 < 0 || s1+t1 > 1)
        return false;

    if (intersectionData)
    {
        intersectionData->d = d;
        intersectionData->pos = ray.at(d);
        intersectionData->n = tripolate<Vector3f>(  m_normals[triangle.v0.n],
                                                    m_normals[triangle.v1.n],
                                                    m_normals[triangle.v2.n],
                                                    t1, s1, 1-s1-t1);
        Vector2f interpolatedUV = tripolate<Vector2f>(m_uvs[triangle.v0.uv],
                                                      m_uvs[triangle.v1.uv],
                                                      m_uvs[triangle.v2.uv],
                                                      t1, s1, 1-s1-t1);

        intersectionData->c = m_tex ? m_tex->sampleColor(interpolatedUV) :
                                        tripolate<Color>(m_colors[triangle.v0.c],
                                                         m_colors[triangle.v1.c],
                                                         m_colors[triangle.v2.c],
                                                         t1, s1, 1-s1-t1);
        intersectionData->mat = m_mat;
        intersectionData->blendFactor = 0.0;
    }
    return true;
}

ComplexObject* createCube(Material* mat, float sideLength, Texture *tex)
{
    Vector3f positionsArray[] =
    {
        {sideLength/2,   sideLength/2,  sideLength/2},
        {sideLength/2,   sideLength/2,  -sideLength/2},
        {sideLength/2,   -sideLength/2, sideLength/2},
        {sideLength/2,   -sideLength/2, -sideLength/2},
        {-sideLength/2,  sideLength/2,  sideLength/2},
        {-sideLength/2,  sideLength/2,  -sideLength/2},
        {-sideLength/2,  -sideLength/2, sideLength/2},
        {-sideLength/2,  -sideLength/2, -sideLength/2},
    };
    std::vector<Vector3f> positions(positionsArray, positionsArray + sizeof(positionsArray) / sizeof(Vector3f));

    Vector3f normalsArray[] =
    {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
        {-1, 0, 0},
        {0, -1, 0},
        {0, 0, -1},
    };
    std::vector<Vector3f> normals(normalsArray, normalsArray + sizeof(normalsArray) / sizeof(Vector3f));

    Vector2f uvsArray[] =
    {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1},
    };
    std::vector<Vector2f> uvs(uvsArray, uvsArray + sizeof(uvsArray) / sizeof(Vector2f));

    Color colorsArray[] =
    {
        {1, 1, 0},
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0},
    };
    std::vector<Color> colors(colorsArray, colorsArray + sizeof(colorsArray) / sizeof(Color));

    ComplexObject::Triangle trianglesArray[] =
    {
        /* RIGHT FACE */
        {{1, 0, 1, 3}, {0, 0, 3, 2}, {2, 0, 2, 1}},
        {{1, 0, 1, 3}, {2, 0, 2, 1}, {3, 0, 0, 0}},

        /* TOP FACE */
        {{4, 1, 1, 0}, {0, 1, 3, 3}, {1, 1, 2, 2}},
        {{4, 1, 1, 0}, {1, 1, 2, 2}, {5, 1, 0, 1}},

        /* FRONT FACE */
        {{5, 5, 1, 2}, {1, 5, 3, 0}, {3, 5, 2, 1}},
        {{5, 5, 1, 2}, {3, 5, 2, 1}, {7, 5, 0, 3}},

        /* BOTTOM FACE */
        {{6, 4, 1, 0}, {2, 4, 3, 1}, {3, 4, 2, 3}},
        {{6, 4, 1, 0}, {3, 4, 2, 3}, {7, 4, 0, 1}},

        /* BACK FACE */
        {{0, 2, 1, 1}, {4, 2, 3, 0}, {6, 2, 2, 2}},
        {{0, 2, 1, 1}, {6, 2, 2, 2}, {2, 2, 0, 3}},

        /* LEFT FACE */
        {{4, 3, 1, 2}, {5, 3, 3, 0}, {7, 3, 2, 1}},
        {{4, 3, 1, 2}, {7, 3, 2, 1}, {6, 3, 0, 3}},
    };
    std::vector<ComplexObject::Triangle> triangles(trianglesArray, trianglesArray + sizeof(trianglesArray) / sizeof(ComplexObject::Triangle));
    return new ComplexObject(mat, positions, normals, uvs, colors, triangles, tex);
}
