#include <iostream>

#include "Image.h"

int main()
{
    Image img(10, 10);

    for(int i = 0; i < 10; ++i)
    {
        img.setPixel(i, i, Color(255));
    }

    img.saveImage("img");
    return 0;
}
