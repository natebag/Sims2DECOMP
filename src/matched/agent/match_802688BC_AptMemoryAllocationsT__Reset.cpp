struct AptMemoryAllocationsT {
    int a0;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int a7;

    void Reset(void);
};

void AptMemoryAllocationsT::Reset(void) {
    a0 = 0;
    a1 = 0;
    a4 = 0;
    a5 = 0;
    a2 = 0;
    a3 = 0;
    a6 = 0;
    a7 = 0;
}
