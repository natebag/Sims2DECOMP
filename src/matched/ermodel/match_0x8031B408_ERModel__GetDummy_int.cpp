// FLAGS: -fno-schedule-insns
// 0x8031B408 ERModel::GetDummy(int) (16B)
// mulli r4,r4,88; lwz r3,0x11c(3); add r3,r3,r4; blr  -- &m_dummies[i], stride 88
struct ERDummy { char data[88]; };

struct ERModel {
    char pad[0x11C];
    ERDummy* m_dummies;     // 0x11C
    ERDummy* GetDummy(int i);
};

ERDummy* ERModel::GetDummy(int i) {
    return &m_dummies[i];
}
