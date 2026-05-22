// 0x80089798 CreateASimBaseState::OnBackOut(void) (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32697; mr 28,3; addi 31,9,23428; lwz 3,0x3c(31); lwz 0,0x1630(3); cmpwi 0,0; bne 0f; bl _s80089798_0; 0:; lwz 3,0x3c(31); bl _s80089798_1; cmpwi 3,0; beq 4f; lwz 3,0x8(28); bl _s80089798_2; lwz 11,0x3c(31); cmpwi 11,0; beq 1f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 11,0x54(31); li 29,0; stw 29,0x3c(31); cmpwi 11,0; beq 2f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 2:; lis 30,-32693; lis 4,-17873; addi 30,30,31260; ori 4,4,14905; li 5,0; li 6,0; stw 29,0x54(31); mr 3,30; bl _s80089798_3; lis 4,-17873; mr 3,30; ori 4,4,14905; li 5,1; bl _s80089798_4; lwz 3,-24508(13); li 0,1; stw 0,0x2c(28); cmpwi 3,0; beq 3f; addi 3,3,48; li 4,32; bl _s80089798_5; lwz 3,-24508(13); li 4,32; addi 3,3,48; bl _s80089798_6; 3:; lwz 3,-21492(13); li 4,2; bl _s80089798_7; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80089798_0();
extern "C" void _s80089798_1();
extern "C" void _s80089798_2();
extern "C" void _s80089798_3();
extern "C" void _s80089798_4();
extern "C" void _s80089798_5();
extern "C" void _s80089798_6();
extern "C" void _s80089798_7();
extern "C" void f_80089798() {}
