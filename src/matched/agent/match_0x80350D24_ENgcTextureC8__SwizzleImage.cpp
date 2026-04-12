// 0x80350D24 ENgcTextureC8::SwizzleImage (48b)
typedef unsigned char uchar;

void ENgcTextureUtil__SwizzleToC8(uchar *src, int w, int h, uchar *dst);

struct ENgcTextureC8 {
    void SwizzleImage(uchar *src, int w, int h, uchar *dst);
};

void ENgcTextureC8::SwizzleImage(uchar *src, int w, int h, uchar *dst) {
    ENgcTextureUtil__SwizzleToC8(src, w, h, dst);
}
