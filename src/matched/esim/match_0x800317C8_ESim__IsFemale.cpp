// 0x800317C8 (36 bytes)
/* ESim::IsFemale(void) */

struct ESim_IsFemale {
    char pad_00[0x3D0];
    void *m_inner;

    int IsMale(void);
    int IsFemale(void);
};

int ESim_IsFemale::IsFemale(void) {
    int r = IsMale();
    return r ^ 1;
}
