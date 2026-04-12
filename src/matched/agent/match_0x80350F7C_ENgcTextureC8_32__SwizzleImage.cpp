// 0x80350F7C ENgcTextureC8_32::SwizzleImage (48b)
typedef unsigned char uchar;

void ENgcTextureUtil__SwizzleToC8(uchar *src, int w, int h, uchar *dst);

struct ENgcTextureC8_32 {
    void SwizzleImage(uchar *src, int w, int h, uchar *dst);
};

void ENgcTextureC8_32::SwizzleImage(uchar *src, int w, int h, uchar *dst) {
    ENgcTextureUtil__SwizzleToC8(src, w, h, dst);
}
