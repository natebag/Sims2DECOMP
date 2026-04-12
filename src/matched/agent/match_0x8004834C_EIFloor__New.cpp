// 0x8004834C EIFloor::New (40b)
struct EIFloor {
    char _pad[304];
    static void *operator new(unsigned int);
    EIFloor(void);
};

EIFloor *EIFloor__New(void) {
    EIFloor *p = new EIFloor;
    return p;
}
