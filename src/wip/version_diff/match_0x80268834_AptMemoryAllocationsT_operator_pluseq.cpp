struct AptMemoryAllocationsT {
    int a0;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int a7;
    AptMemoryAllocationsT& operator+=(AptMemoryAllocationsT& other);
};

AptMemoryAllocationsT& AptMemoryAllocationsT::operator+=(AptMemoryAllocationsT& other) {
    a0 += other.a0;
    a1 += other.a1;
    a4 += other.a4;
    a5 += other.a5;
    a2 += other.a2;
    a3 += other.a3;
    a6 += other.a6;
    a7 += other.a7;
    return *this;
}
