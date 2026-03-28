/* Effects::Mat4Copy34 - 116 bytes at 0x8035301C */

struct EMat4 {
    float m[4][4];
};

namespace Effects {
    void Mat4Copy34(EMat4& src, EMat4& dst);
}

void Effects::Mat4Copy34(EMat4& src, EMat4& dst) {
    float *s0 = src.m[0];
    float *d0 = dst.m[0];
    float *s1 = src.m[1];
    float *d1 = dst.m[1];
    float *s2 = src.m[2];
    float *d2 = dst.m[2];

    d0[0] = s0[0];
    d0[1] = s0[1];
    d0[2] = s0[2];
    d0[3] = s0[3];
    d1[0] = s1[0];
    d1[1] = s1[1];
    d1[2] = s1[2];
    d1[3] = s1[3];
    d2[0] = s2[0];
    d2[1] = s2[1];
    d2[2] = s2[2];
    d2[3] = s2[3];
}
