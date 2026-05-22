// 0x800F29C4 ObjectFolderImpl::GetPath(void) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 3,3,1360; bl _s800F29C4_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800F29C4_0();
extern "C" void f_800F29C4() {}
