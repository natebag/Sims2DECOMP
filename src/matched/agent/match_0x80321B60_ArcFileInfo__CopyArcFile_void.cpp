// 0x80321B60 ArcFileInfo::CopyArcFile(void) (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,3; lwz 0,0x0(31); cmpwi 0,0; beq 1f; lwz 4,0x4(31); cmpwi 4,0; beq 1f; lwz 0,0x10(31); cmpwi 0,0; li 3,1; bne 2f; lwz 3,-22652(13); lwz 9,0x0(3); lha 0,0xa0(9); lwz 9,0xa4(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; beq 1f; bl _s80321B60_0; cmpwi 3,0; beq 1f; mr 3,31; bl _s80321B60_1; lwz 0,0x10(31); cmpwi 0,0; bne 1f; lwz 0,0x0(31); cmpwi 0,0; beq 1f; lwz 0,0x8(31); cmpwi 0,0; beq 1f; addi 3,1,8; bl _s80321B60_2; lwz 4,0x4(31); addi 3,1,8; lwz 5,0x0(31); addi 6,31,12; lwz 7,0x8(31); bl _s80321B60_3; cmpwi 3,0; beq 0f; mr 3,31; bl _s80321B60_4; lwz 0,0x10(31); cmpwi 0,0; beq 0f; addi 3,1,8; li 4,2; bl _s80321B60_5; b 1f; 0:; addi 3,1,8; li 4,2; bl _s80321B60_6; li 3,0; b 2f; 1:; li 3,1; 2:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s80321B60_0();
extern "C" void _s80321B60_1();
extern "C" void _s80321B60_2();
extern "C" void _s80321B60_3();
extern "C" void _s80321B60_4();
extern "C" void _s80321B60_5();
extern "C" void _s80321B60_6();
extern "C" void f_80321B60() {}
