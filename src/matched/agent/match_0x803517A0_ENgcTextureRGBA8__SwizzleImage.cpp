// 0x803517A0 ENgcTextureRGBA8::SwizzleImage (48b)
typedef unsigned char uchar;

void ENgcTextureUtil__SwizzleToRGBA8(uchar *src, int w, int h, uchar *dst);

struct ENgcTextureRGBA8 {
    void SwizzleImage(uchar *src, int w, int h, uchar *dst);
};

void ENgcTextureRGBA8::SwizzleImage(uchar *src, int w, int h, uchar *dst) {
    ENgcTextureUtil__SwizzleToRGBA8(src, w, h, dst);
}
