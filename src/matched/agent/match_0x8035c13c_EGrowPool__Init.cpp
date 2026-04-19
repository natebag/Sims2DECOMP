// 0x8035c13c (20B) EGrowPool::Init(void)
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// Store order: 8, 0, 4 — scheduler would reorder without flags.

struct EGrowPool {
    int field_0;
    int field_4;
    int field_8;
    void Init();
};

void EGrowPool::Init() {
    field_8 = 0;
    field_0 = 0;
    field_4 = 0;
}
