// 0x800D545C NghResFile::StoreThumbGUID(unsigned (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 4,4,-1; addi 3,3,404; rlwinm 4,4,2,0,29; stwx 5,3,4"
extern "C" void f_800D545C() {}
