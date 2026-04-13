// 0x8035163C ENgcTextureRGB5A3::SwizzleImage (48b)
typedef unsigned char uchar;

void ENgcTextureUtil__SwizzleToRGB5A3(uchar *src, int w, int h, uchar *dst);

struct ENgcTextureRGB5A3 {
    void SwizzleImage(uchar *src, int w, int h, uchar *dst);
};

void ENgcTextureRGB5A3::SwizzleImage(uchar *src, int w, int h, uchar *dst) {
    ENgcTextureUtil__SwizzleToRGB5A3(src, w, h, dst);
}
