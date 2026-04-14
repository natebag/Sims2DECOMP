typedef unsigned char u8;

int SAnimator2_EndAutoRun(u8* self) {
    int state = *(int*)(self + 0x600);
    int ret;
    if (state != 1) {
        ret = 0;
    } else {
        u8* person = *(u8**)(self + 4);
        u8* vtable = *(u8**)person;
        u8* sub = *(u8**)(vtable + 4);
        short offset = *(short*)(sub + 0x1E8);
        int func = *(int*)(sub + 0x1EC);
        u8* obj = vtable + offset;
        ((void (*)(u8*, int, int))func)(obj, 17, 0);
        *(int*)(self + 0x600) = 0;
        ret = 1;
    }
    return ret;
}
