// 0x80350FAC ENgcTextureC8_32::UnswizzleImage (48b)
typedef unsigned char uchar;

void ENgcTextureUtil__SwizzleFromC8(uchar *src, int w, int h, uchar *dst);

struct ENgcTextureC8_32 {
    void UnswizzleImage(uchar *src, int w, int h, uchar *dst);
};

void ENgcTextureC8_32::UnswizzleImage(uchar *src, int w, int h, uchar *dst) {
    ENgcTextureUtil__SwizzleFromC8(src, w, h, dst);
}
