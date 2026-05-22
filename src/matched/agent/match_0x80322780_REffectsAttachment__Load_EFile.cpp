// 0x80322780 REffectsAttachment::Load(EFile (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 30,0x28(1); stw 0,0x34(1); mr 31,3; mr. 30,4; beq 6f; addi 3,1,8; bl _s80322780_0; lis 5,17729; addi 3,1,8; mr 4,30; ori 5,5,21571; li 6,2; li 7,2; bl _s80322780_1; cmpwi 3,0; bne 0f; mr 3,31; mr 4,30; bl _s80322780_2; addi 3,1,8; li 4,2; bl _s80322780_3; b 6f; 0:; addi 3,1,8; bl _s80322780_4; lwz 5,0x18(1); lwz 0,0x10(31); cmpwi 5,0; rlwimi 0,5,8,0,23; stw 0,0x10(31); beq 5f; li 9,0; addi 3,31,20; li 10,0; rlwinm 5,5,29,3,31; stw 9,0x20(1); stw 10,0x24(1); addi 6,1,32; lwz 9,0x14(31); lwz 4,0x4(3); subf 0,9,4; srawi 0,0,3; cmplw 5,0; bge 3f; rlwinm 0,5,3,0,28; add 0,0,9; lwz 11,0x4(3); mr 9,0; cmpw 0,11; beq 2f; 1:; addi 9,9,8; cmpw 9,11; bne 1b; 2:; stw 0,0x4(3); b 4f; 3:; subf 5,0,5; bl _s80322780_5; 4:; lwz 9,0x28(30); lwz 4,0x14(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; lwz 5,0x18(1); mtspr 8,0; blrl; 5:; addi 3,1,8; li 4,2; bl _s80322780_6; 6:; lwz 0,0x34(1); mtspr 8,0; lmw 30,0x28(1); addi 1,1,48"
extern "C" void _s80322780_0();
extern "C" void _s80322780_1();
extern "C" void _s80322780_2();
extern "C" void _s80322780_3();
extern "C" void _s80322780_4();
extern "C" void _s80322780_5();
extern "C" void _s80322780_6();
extern "C" void f_80322780() {}
