// 0x800304A8 (40B) EIWallPart::New(void)
// Static factory: operator new + ctor. Size 952.

struct EIWallPart_N {
    char _pad[952];
    static void* operator new(unsigned int);
    EIWallPart_N();
};

EIWallPart_N* EIWallPart__New(void) {
    EIWallPart_N* p = new EIWallPart_N;
    return p;
}
