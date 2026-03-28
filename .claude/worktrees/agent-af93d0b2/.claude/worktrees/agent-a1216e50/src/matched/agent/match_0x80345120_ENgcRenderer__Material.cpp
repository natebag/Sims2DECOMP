/* ENgcRenderer::Material(EDLEntry *) - 132 bytes at 0x80345120 */

struct EDLEntry {
    char pad[4];
    char *data;  /* 0x04 */
};

class ENgcRenderer {
public:
    char pad0[0x510];
    int m_dirty;          /* 0x510 */
    char pad1[4];
    char m_matdata[0x30]; /* 0x518 */

    void Material(EDLEntry *entry);
};

void ENgcRenderer::Material(EDLEntry *entry) {
    float *src = (float *)entry->data;
    float *dst0 = (float *)(m_matdata);
    float *dst1 = (float *)(m_matdata + 0x10);
    float *dst2 = (float *)(m_matdata + 0x20);
    float *src1 = src + 4;
    float *src2 = (float *)(((char *)src) + 0x20);

    dst0[0] = src[0];
    dst0[1] = src[1];
    dst0[2] = src[2];
    dst0[3] = src[3];
    dst1[0] = src1[0];
    dst1[1] = src1[1];
    dst1[2] = src1[2];
    dst1[3] = src1[3];
    ((int *)dst2)[0] = ((int *)src2)[0];
    ((int *)dst2)[2] = ((int *)src2)[2];
    ((int *)dst2)[1] = ((int *)src2)[1];
    dst0[11] = src[11];
    m_dirty = 1;
}
