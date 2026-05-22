// 0x80088ED4 ISimsMultiTileObjectModel::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lmw 30,0x8(1); addi 1,1,16"
extern "C" int f_80088ED4() {}
