// 0x80321A78 ArcFileInfo::Reset(void) (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; lwz 0,0x0(31); cmpwi 0,0; beq 1f; lwz 4,0x4(31); cmpwi 4,0; beq 1f; lwz 11,-22652(13); li 0,0; stw 0,0xc(31); stw 0,0x10(31); lwz 9,0x0(11); lha 3,0xa0(9); lwz 0,0xa4(9); add 3,11,3; mtspr 8,0; blrl; mr. 4,3; beq 0f; lwz 3,-22652(13); lwz 9,0x0(3); lha 0,0xb0(9); lwz 9,0xb4(9); add 3,3,0; mtspr 8,9; blrl; 0:; lwz 5,0x0(31); lis 30,-32694; addi 31,1,8; lis 6,-32702; addi 6,6,2880; addi 3,30,-10620; mr 4,31; li 7,0; lis 8,-32768; li 9,0; bl _s80321A78_0; cmpwi 3,0; beq 1f; lwz 3,0x8(1); lwz 9,0x28(3); lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; addi 3,30,-10620; mr 4,31; bl _s80321A78_1; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s80321A78_0();
extern "C" void _s80321A78_1();
extern "C" void f_80321A78() {}
