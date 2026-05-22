// 0x800F129C ObjectFolderImpl::Save(iResFile (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 5,21569; li 6,1; ori 5,5,21588; li 7,0; bl _s800F129C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800F129C_0();
extern "C" void f_800F129C() {}
