// 0x80350D54 ENgcTextureC8::UnswizzleImage (48b)
typedef unsigned char uchar;

void ENgcTextureUtil__SwizzleFromC8(uchar *src, int w, int h, uchar *dst);

struct ENgcTextureC8 {
    void UnswizzleImage(uchar *src, int w, int h, uchar *dst);
};

void ENgcTextureC8::UnswizzleImage(uchar *src, int w, int h, uchar *dst) {
    ENgcTextureUtil__SwizzleFromC8(src, w, h, dst);
}
