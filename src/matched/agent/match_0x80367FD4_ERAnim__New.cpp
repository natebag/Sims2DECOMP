// 0x80367FD4 ERAnim::New (40b)
struct ERAnim {
    char _pad[160];
    static void *operator new(unsigned int);
    ERAnim(void);
};

ERAnim *ERAnim__New(void) {
    ERAnim *p = new ERAnim;
    return p;
}
