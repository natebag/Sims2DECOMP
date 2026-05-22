// 0x800F15D0 ObjectFolderImpl::GetCameraBlurByName(char (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; mr 30,3; lis 4,-32706; lwz 3,0x690(30); addi 4,4,-19192; bl _s800F15D0_0; mr 4,3; mr 5,29; lwz 3,0x690(30); bl _s800F15D0_1; mr. 3,3; bne 0f; li 3,0; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800F15D0_0();
extern "C" void _s800F15D0_1();
extern "C" void f_800F15D0() {}
