// 0x8035166C ENgcTextureRGB5A3::UnswizzleImage (48b)
typedef unsigned char uchar;

void ENgcTextureUtil__SwizzleFromRGB5A3(uchar *src, int w, int h, uchar *dst);

struct ENgcTextureRGB5A3 {
    void UnswizzleImage(uchar *src, int w, int h, uchar *dst);
};

void ENgcTextureRGB5A3::UnswizzleImage(uchar *src, int w, int h, uchar *dst) {
    ENgcTextureUtil__SwizzleFromRGB5A3(src, w, h, dst);
}
