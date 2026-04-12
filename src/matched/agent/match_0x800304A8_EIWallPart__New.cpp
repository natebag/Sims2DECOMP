// 0x800304A8 EIWallPart::New (40b)
struct EIWallPart {
    char _pad[952];
    static void *operator new(unsigned int);
    EIWallPart(void);
};

EIWallPart *EIWallPart__New(void) {
    EIWallPart *p = new EIWallPart;
    return p;
}
