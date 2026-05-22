// 0x800B6A88 FamilyImpl::GetExportName(StringBuffer2 (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 9,0x0(30); lha 3,0x80(9); lwz 0,0x84(9); add 3,30,3; mtspr 8,0; blrl; lis 4,-32706; mr 3,29; addi 4,4,-26152; li 5,-1; bl _s800B6A88_0; lwz 4,0x8(30); mr 3,29; bl _s800B6A88_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800B6A88_0();
extern "C" void _s800B6A88_1();
extern "C" void f_800B6A88() {}
