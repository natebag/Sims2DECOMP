// 0x800317C8 (36 bytes)
/* ESim::IsFemale(void) */

struct ESim {
    char pad_00[0x3D0];
    void *m_inner;

    int IsMale(void);
    int IsFemale(void);
};

int ESim::IsFemale(void) {
    int r = IsMale();
    return r ^ 1;
}
