// 0x8031B418 ERModel::GetCamera(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 4,4,88; lwz 3,0x128(3); add 3,3,4"
extern "C" int f_8031B418() {}
