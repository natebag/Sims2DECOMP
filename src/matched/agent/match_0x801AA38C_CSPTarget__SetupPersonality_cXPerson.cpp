// 0x801AA38C CSPTarget::SetupPersonality(cXPerson (496 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; mr 31,3; lwz 9,0x4(29); addi 30,31,276; lwz 0,0x14c(9); lha 3,0x148(9); mtspr 8,0; add 3,29,3; blrl; bl _s801AA38C_0; stw 3,0x110(31); lha 3,0x112(31); bl _s801AA38C_1; mr 4,3; mr 3,30; bl _s801AA38C_2; lwz 0,0x110(31); cmplwi 0,12; bgt 0f; lis 9,-32705; lwz 10,0x0(31); addi 9,9,27268; rlwinm 0,0,2,0,29; lis 11,-32705; lwzx 5,9,0; addi 4,11,-4436; cmpwi 10,0; beq 1f; lwz 3,0x1c(31); cmpwi 3,0; beq 1f; lwz 6,0x7c(31); li 7,0; bl _s801AA38C_3; b 1f; 0:; bl _s801AA38C_4; lwz 0,0x0(31); lis 9,-32705; mr 5,3; addi 4,9,-4436; cmpwi 0,0; beq 1f; lwz 3,0x1c(31); cmpwi 3,0; beq 1f; lwz 6,0x7c(31); li 7,0; bl _s801AA38C_5; 1:; lwz 9,0x4(29); li 4,6; lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,29,3; blrl; stw 3,0xfc(31); li 4,2; lwz 9,0x4(29); lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,29,3; blrl; stw 3,0x100(31); li 4,5; lwz 9,0x4(29); lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,29,3; blrl; stw 3,0x104(31); li 4,7; lwz 9,0x4(29); lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,29,3; blrl; stw 3,0x108(31); li 4,3; lwz 9,0x4(29); lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,29,3; blrl; li 0,5; addi 6,31,252; mtspr 9,0; stw 3,0x10c(31); lis 4,20971; lis 5,10381; mr 3,6; ori 4,4,34079; ori 5,5,61643; li 7,0; 2:; lwzx 11,7,3; mulhw 0,11,4; srawi 8,11,31; mulhw 9,11,5; srawi 0,0,5; subf 10,8,0; mr 0,10; srawi 9,9,4; mulli 10,10,100; subf 9,8,9; subf 10,10,11; cmpwi 10,49; ble 3f; stwx 9,7,6; b 4f; 3:; stwx 0,7,6; 4:; addi 7,7,4; bdnz 2b; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801AA38C_0();
extern "C" void _s801AA38C_1();
extern "C" void _s801AA38C_2();
extern "C" void _s801AA38C_3();
extern "C" void _s801AA38C_4();
extern "C" void _s801AA38C_5();
extern "C" void f_801AA38C() {}
