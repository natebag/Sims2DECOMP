// 0x80175EDC HelpDialog::SpawnHelpDialog(int, (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-552(1); mfspr 0,8; stmw 24,0x208(1); stw 0,0x22c(1); mr 24,4; mr 25,3; mr 29,5; lis 4,-32706; mr 28,6; mr 27,7; mr 26,8; addi 4,4,8868; addi 3,1,8; crxor 6,6,6; bl _s80175EDC_0; addi 30,1,264; lis 4,-32706; mr 5,29; addi 4,4,8880; mr 3,30; crxor 6,6,6; bl _s80175EDC_1; mr 3,25; mr 4,24; mr 6,30; mr 7,28; mr 8,27; mr 9,26; addi 5,1,8; bl _s80175EDC_2; lwz 0,0x22c(1); mtspr 8,0; lmw 24,0x208(1); addi 1,1,552"
extern "C" void _s80175EDC_0();
extern "C" void _s80175EDC_1();
extern "C" void _s80175EDC_2();
extern "C" void f_80175EDC() {}
