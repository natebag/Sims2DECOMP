// FLAGS: -fno-schedule-insns
// 0x802688BC AptMemoryAllocationsT::Reset (40B)

struct AptMemoryAllocationsT {
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    void Reset();
};

void AptMemoryAllocationsT::Reset() {
    field_1C = 0;
    field_00 = 0;
    field_04 = 0;
    field_10 = 0;
    field_14 = 0;
    field_08 = 0;
    field_0C = 0;
    field_18 = 0;
}
