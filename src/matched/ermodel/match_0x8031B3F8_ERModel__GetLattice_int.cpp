// FLAGS: -fno-schedule-insns
// 0x8031B3F8 ERModel::GetLattice(int) (16B)
// mulli r4,r4,176; lwz r3,0x110(3); add r3,r3,r4; blr  -- &m_lattices[i], stride 176
struct ERLattice { char data[176]; };

struct ERModel {
    char pad[0x110];
    ERLattice* m_lattices;  // 0x110
    ERLattice* GetLattice(int i);
};

ERLattice* ERModel::GetLattice(int i) {
    return &m_lattices[i];
}
