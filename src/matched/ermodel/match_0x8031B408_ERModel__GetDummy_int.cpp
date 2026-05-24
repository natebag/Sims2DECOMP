// 0x8031B408 ERModel::GetDummy(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 4,4,88; lwz 3,0x11c(3); add 3,3,4"

struct ERModel {
    void GetDummy();
};

void ERModel::GetDummy() {
}
