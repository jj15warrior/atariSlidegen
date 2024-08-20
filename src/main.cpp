#include <bits/stdc++.h>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"
#include "stb_image_resize2.h"
using namespace std;

typedef struct color{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};

const double paletteLAB[] = {
    23.6714,0.537196,0.00159145,
    90.594,6.47322,67.6177,
    87.0895,20.9209,21.3131,
    87.946,35.6443,7.45236,
    86.7808,49.7505,-25.6815,
    86.4125,53.4359,-42.8298,
    87.1395,48.0619,-51.4168,
    90.1326,17.5564,-47.0506,
    91.9281,-3.68366,-34.9256,
    93.6571,-24.5008,-16.216,
    95.173,-46.4178,16.3455,
    95.9557,-57.0706,71.0914,
    95.7305,-47.6658,91.7539,
    94.6902,-30.7413,91.8397,
    93.0072,-13.2026,91.5156,
    90.594,6.47322,67.6177
};

double F(double input) 
{
    if (input > 0.008856)
        return (pow(input, 0.333333333));
    else
        return ((841/108)*input + 4/29);
}
double distance(color a, color b){

    double Xa = 0.412453*a.r + 0.357580*a.g + 0.189423*a.b;
    double Ya = 0.212671*a.r + 0.715160*a.g + 0.072169*a.b;
    double Za = 0.019334*a.r + 0.119193*a.g + 0.950227*a.b;

    double Xb = 0.412453*b.r + 0.357580*b.g + 0.189423*b.b; 
    double Yb = 0.212671*b.r + 0.715160*b.g + 0.072169*b.b;
    double Zb = 0.019334*b.r + 0.119193*b.g + 0.950227*b.b;

    double Xo = 95.047;
    double Yo = 100;
    double Zo = 108.883;

    Xa /= Xo;
    Ya /= Yo;
    Za /= Zo;

    Xb /= Xo;
    Yb /= Yo;
    Zb /= Zo;



    if (Xa > 0.008856)
        Xa = cbrt(Xa);
    else
        Xa = (double(841)/108)*Xa + double(4)/29;
    
    if (Ya > 0.008856)
        Ya = cbrt(Ya);
    else
        Ya = (double(841)/108)*Ya + double(4)/29;
    
    if (Za > 0.008856)
        Za = cbrt(Za);
    else
        Za = (double(841)/108)*Za + double(4)/29;


    if (Xb > 0.008856)
        Xb = cbrt(Xb);
    else
        Xb = (double(841)/108)*Xb + double(4)/29;
    
    if (Yb > 0.008856)
        Yb = cbrt(Yb);
    else
        Yb = (double(841)/108)*Yb + double(4)/29;
    
    if (Zb > 0.008856)
        Zb = cbrt(Zb);
    else
        Zb = (double(841)/108)*Zb + double(4)/29;
    
    double La = 116 * Ya - 16;
    double aa = 500 * (Xa- Ya);
    double ba = 200 * (Ya - Za);

    double Lb = 116 * Yb - 16;
    double ab = 500 * (Xb- Yb); 
    double bb = 200 * (Yb - Zb);


    return sqrt((La-Lb)*(La-Lb) + (aa-ab)*(aa-ab) + (ba-bb)*(ba-bb));
}
double distance(color a, double Lb, double ab, double bb){
    double Xa = 0.412453*a.r + 0.357580*a.g + 0.189423*a.b;
    double Ya = 0.212671*a.r + 0.715160*a.g + 0.072169*a.b;
    double Za = 0.019334*a.r + 0.119193*a.g + 0.950227*a.b;

    double Xo = 95.047;
    double Yo = 100;
    double Zo = 108.883;

    Xa /= Xo;
    Ya /= Yo;
    Za /= Zo;


    if (Xa > 0.008856)
        Xa = cbrt(Xa);
    else
        Xa = (double(841)/108)*Xa + double(4)/29;
    
    if (Ya > 0.008856)
        Ya = cbrt(Ya);
    else
        Ya = (double(841)/108)*Ya + double(4)/29;
    
    if (Za > 0.008856)
        Za = cbrt(Za);
    else
        Za = (double(841)/108)*Za + double(4)/29;


    double La = 116 * Ya - 16;
    double aa = 500 * (Xa- Ya);
    double ba = 200 * (Ya - Za);




    return sqrt((La-Lb)*(La-Lb) + (aa-ab)*(aa-ab) + (ba-bb)*(ba-bb));
}

color closest(color a){
    short minidx = 0, mindist = SHRT_MAX;
    short dist;
    for(short i=0;i<16*3;i+=3){
        dist = distance(a, paletteLAB[i], paletteLAB[i+1], paletteLAB[i+2]);
        if(dist < mindist){
            mindist = dist;
            minidx = i;
        }
    }
    return 
}

int main(){
    //unsigned char *data;
    int w=0,h=0;
    //data = stbi_load("image.png", &w, &h, 0, 4);
    //unsigned char data_copy[w*h*4];
    //resize to 640x480
    //stbir_resize_uint8_linear(data, w, h, 0, data_copy, 640, 480, 0, STBIR_RGBA);
    
    
    //stbi_write_png("image2.png", 640,480, 4, data_copy, 0);
}
