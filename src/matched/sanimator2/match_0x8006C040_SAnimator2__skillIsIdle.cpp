/* 0x8006C040 (84 bytes) - SAnimator2::skillIsIdle(void) */
struct SAnimator2 {
    char pad[4];
    unsigned char* m_pPerson;
    int skillIsIdle();
};

int SAnimator2::skillIsIdle() {
    unsigned char* person = m_pPerson;
    int ret = 0;
    unsigned char* vtable = *(unsigned char**)(person + 4);
    short offset = *(short*)(vtable + 0xA8);
    int func = *(int*)(vtable + 0xAC);
    unsigned char* obj = person + offset;
    int result = ((int (*)(unsigned char*))func)(obj);
    if (result != 0) {
        ret = 1;
    }
    return ret;
}
