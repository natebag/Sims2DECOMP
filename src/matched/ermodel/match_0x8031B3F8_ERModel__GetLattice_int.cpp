// 0x8031B3F8 ERModel::GetLattice(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 4,4,176; lwz 3,0x110(3); add 3,3,4"

struct ERModel {
    void GetLattice();
};

void ERModel::GetLattice() {
}
