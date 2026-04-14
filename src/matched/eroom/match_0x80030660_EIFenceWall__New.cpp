// 0x80030660 EIFenceWall::New (40b)
struct EIFenceWall {
    char _pad[952];
    static void *operator new(unsigned int);
    EIFenceWall(void);
};

EIFenceWall *EIFenceWall__New(void) {
    EIFenceWall *p = new EIFenceWall;
    return p;
}
