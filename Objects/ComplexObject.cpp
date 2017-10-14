#include "ComplexObject.h"

#include <iostream>
#include <fstream>
#include <string>

#include <cstdlib>
#include <Eigen/StdVector>

ComplexObject* ComplexObject::loadFromFile(Material *mat, const std::string& fileName)
{
    std::vector<Vector3f, aligned_allocator<Vector3f>> vertices;
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
                // handle case of normals
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

bool ComplexObject::intersect(const Ray& ray, IntersectionData *intersectionData) const
{
    bool hasIntersected = false;
    IntersectionData temp;
    IntersectionData best;
    best.d = INT_MAX;
    for(const Triangle* triangle: m_triangles)
    {
        if (triangle->intersect(ray, &temp))
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
