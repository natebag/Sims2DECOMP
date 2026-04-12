// 0x803517D0 ENgcTextureRGBA8::UnswizzleImage (48b)
typedef unsigned char uchar;

void ENgcTextureUtil__SwizzleFromRGBA8(uchar *src, int w, int h, uchar *dst);

struct ENgcTextureRGBA8 {
    void UnswizzleImage(uchar *src, int w, int h, uchar *dst);
};

void ENgcTextureRGBA8::UnswizzleImage(uchar *src, int w, int h, uchar *dst) {
    ENgcTextureUtil__SwizzleFromRGBA8(src, w, h, dst);
}
