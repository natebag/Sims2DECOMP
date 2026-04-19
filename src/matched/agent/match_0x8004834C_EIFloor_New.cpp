// 0x8004834C (40B) EIFloor::New(void)
// Static factory: operator new + ctor. Size 304.

struct EIFloor_N {
    char _pad[304];
    static void* operator new(unsigned int);
    EIFloor_N();
};

EIFloor_N* EIFloor__New(void) {
    EIFloor_N* p = new EIFloor_N;
    return p;
}
