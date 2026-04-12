// 0x803508C0 ENgcTextureC4_32::SwizzleImage (48b)
typedef unsigned char uchar;

void ENgcTextureUtil__SwizzleToC4(uchar *src, int w, int h, uchar *dst);

struct ENgcTextureC4_32 {
    void SwizzleImage(uchar *src, int w, int h, uchar *dst);
};

void ENgcTextureC4_32::SwizzleImage(uchar *src, int w, int h, uchar *dst) {
    ENgcTextureUtil__SwizzleToC4(src, w, h, dst);
}
