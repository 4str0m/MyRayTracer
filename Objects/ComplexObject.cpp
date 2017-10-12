#include "ComplexObject.h"

#include <iostream>
#include <fstream>
#include <string>

#include <cstdlib>

ComplexObject* ComplexObject::loadFromFile(Material *mat, std::string fileName)
{
    std::vector<Vector3d> vertices;
    std::vector<Triangle> triangles;

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
                double x = strtod(line.c_str() + 2, &endptr);
                double y = strtod(endptr, &endptr);
                double z = strtod(endptr, &endptr);
                vertices.push_back(Vector3d(x, y, z) * 200);
            }
            if (line[0] == 'v' && line[1] == 'n')
            {
                // handle case of normals
            }
            if (line[0] == 'f' && line[1] == ' ')
            {
                char* endptr = nullptr;
                unsigned long int vertId1 = strtoul(line.c_str()+2, &endptr, 10) - 1;
                while(*endptr != ' ') ++endptr;
                unsigned long int vertId2 = strtoul(endptr, &endptr, 10) - 1;
                while(*endptr != ' ') ++endptr;
                unsigned long int vertId3 = strtoul(endptr, &endptr, 10) - 1;
                triangles.push_back(Triangle(nullptr, vertices[vertId1], vertices[vertId2], vertices[vertId3]));
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
    for(const Triangle& triangle: m_triangles)
    {
        if (triangle.intersect(ray, &temp))
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
