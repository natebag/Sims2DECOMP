typedef unsigned char u8;

int SAnimator2_skillIsIdle(u8* self) {
    u8* person = *(u8**)(self + 4);
    int ret = 0;
    u8* vtable = *(u8**)(person + 4);
    short offset = *(short*)(vtable + 0xA8);
    int func = *(int*)(vtable + 0xAC);
    u8* obj = person + offset;
    int result = ((int (*)(u8*))func)(obj);
    if (result != 0) {
        ret = 1;
    }
    return ret;
}
