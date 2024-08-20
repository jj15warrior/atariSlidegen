#include <bits/stdc++.h>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"
#include "stb_image_resize2.h"
using namespace std;

struct color{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};

int main(){
    unsigned char *data;
    int w,h;
    data = stbi_load("image.png", &w, &h, NULL, 4);
    unsigned char data_copy[w*h*4];
    memset(data_copy, 0, w*h*4);
    //resize to 640x480
    stbir_resize_uint8_linear(data, w, h, 0, data_copy, 640, 480, 0, STBIR_RGBA);
    
    for(int pxindex = 0; pxindex < w*h*4;pxindex+=4){

    }

    stbi_write_png("image2.png", 640,480, 4, data_copy, 0);
    return 0;
}
