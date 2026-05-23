/* 0x800692E4 (112 bytes) - SAnimator2::EndAutoRun(void) */
typedef unsigned char u8;

struct SAnimator2 {
    char pad[4];
    u8* m_pPerson;
    char pad2[0x5F8];
    int m_autoRunState;
    int EndAutoRun();
};

int SAnimator2::EndAutoRun() {
    int ret;
    if (m_autoRunState != 1) {
        ret = 0;
    } else {
        u8* person = m_pPerson;
        u8* vtable = *(u8**)person;
        u8* sub = *(u8**)(vtable + 4);
        short offset = *(short*)(sub + 0x1E8);
        int func = *(int*)(sub + 0x1EC);
        u8* obj = vtable + offset;
        ((void (*)(u8*, int, int))func)(obj, 17, 0);
        m_autoRunState = 0;
        ret = 1;
    }
    return ret;
}
