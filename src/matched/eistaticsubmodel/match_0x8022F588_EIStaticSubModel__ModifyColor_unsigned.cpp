// 0x8022F588 EIStaticSubModel::ModifyColor(unsigned (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x94(3)"
extern "C" void f_8022F588() {}
