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

unsigned char palette[] = {
                4,4,4,
                119,72,11,
                113,60,45,
                132,55,63,
                128,48,111,
                117,47,143,
                100,52,164,
                59,73,164,
                41,86,143,
                30,98,111,
                26,109,63,
                39,113,11,
                57,108,0,
                79,98,0,
                101,86,0,
                119,72,11
};


float distance(color a, color b){

    float Ra = a.r / 255.0f;
    float Ga = a.g / 255.0f;
    float Ba = a.b / 255.0f;

    float Rb = b.r / 255.0f;
    float Gb = b.g / 255.0f;
    float Bb = b.b / 255.0f;


    if(Ra > 0.04045)
        Ra = pow(((Ra + 0.055)/1.055), 2.4);
    else
        Ra /= 12.92;

    if(Rb > 0.04045)
        Rb = pow(((Rb + 0.055)/1.055), 2.4);
    else
        Rb /= 12.92;



    if (Ga > 0.04045)
        Ga = pow((( Ga + 0.055 ) / 1.055 ), 2.4);
    else
        Ga /= 12.92;
    
    if(Gb > 0.04045)
        Gb = pow((( Gb + 0.055 ) / 1.055 ), 2.4);
    else
        Gb /= 12.92;


    if(Ba > 0.04045)
        Ba = pow((( Ba + 0.055 ) / 1.055 ), 2.4);
    else
        Ba /= 12.92;

    if(Bb > 0.04045)
        Bb = pow((( Bb + 0.055 ) / 1.055 ), 2.4);
    else
        Bb /= 12.92;

    Ra *= 100;
    Ga *= 100;
    Ba *= 100;
    Rb *= 100;
    Gb *= 100;
    Bb *= 100;

    float Xa = Ra * 0.4124 + Ga * 0.3576 + Ba * 0.1805;
    float Ya = Ra * 0.2126 + Ga * 0.7152 + Ba * 0.0722;
    float Za = Ra * 0.0193 + Ga * 0.1192 + Ba * 0.9505;

    float Xb = Rb * 0.4124 + Gb * 0.3576 + Bb * 0.1805;
    float Yb = Rb * 0.2126 + Gb * 0.7152 + Bb * 0.0722;
    float Zb = Rb * 0.0193 + Gb * 0.1192 + Bb * 0.9505;

    
    // reference illuminant F8 96.413 100.000 82.333
    float var_Xa = Xa / 96.413;
    float var_Ya = Ya / 100.0;
    float var_Za = Za / 82.333;

    float var_Xb = Xb / 96.413;
    float var_Yb = Yb / 100.0;
    float var_Zb = Zb / 82.333;

    if ( var_Xa > 0.008856 )    var_Xa = pow(var_Xa, ( 1/3 ));
    else                        var_Xa = ( 7.787 * var_Xa ) + ( 16 / 116 );
    if ( var_Ya > 0.008856 )    var_Ya = pow(var_Ya, ( 1/3 ));
    else                        var_Ya = ( 7.787 * var_Ya ) + ( 16 / 116 );
    if ( var_Za > 0.008856 )    var_Za = pow(var_Za, ( 1/3 ));
    else                        var_Za = ( 7.787 * var_Za ) + ( 16 / 116 );

    if ( var_Xb > 0.008856 )    var_Xb = pow(var_Xb, ( 1/3 ));
    else                        var_Xb = ( 7.787 * var_Xb ) + ( 16 / 116 );
    if ( var_Yb > 0.008856 )    var_Yb = pow(var_Yb, ( 1/3 ));
    else                        var_Yb = ( 7.787 * var_Yb ) + ( 16 / 116 );
    if ( var_Zb > 0.008856 )    var_Zb = pow(var_Zb, ( 1/3 ));
    else                        var_Zb = ( 7.787 * var_Zb ) + ( 16 / 116 );
    

    float cieLa = ( 116 * var_Ya ) - 16;
    float cieAa = 500 * ( var_Xa - var_Ya );
    float cieBa = 200 * ( var_Ya - var_Za );

    float cieLb = ( 116 * var_Yb ) - 16;
    float cieAb = 500 * ( var_Xb - var_Yb );
    float cieBb = 200 * ( var_Yb - var_Zb );

    cout << cieLa << " " << cieAa << " " << cieBa << endl;

    return sqrt(pow(cieLa - cieLb, 2) + pow(cieAa - cieAb, 2) + pow(cieBa - cieBb, 2));
}


color closest(color a){

}

int main(){
    unsigned char *data;
    int w,h;
    data = stbi_load("image.png", &w, &h, NULL, 4);
    unsigned char data_copy[w*h*4];
    memset(data_copy, 0, w*h*4);
    //resize to 640x480
    stbir_resize_uint8_linear(data, w, h, 0, data_copy, 640, 480, 0, STBIR_RGBA);
    
    for(int i=0;i<16*3;i+=3){
        distance(color{palette[i], palette[i+1], palette[i+2]}, color{palette[i], palette[i+1], palette[i+2]});
    }

    stbi_write_png("image2.png", 640,480, 4, data_copy, 0);
    return 0;
}
