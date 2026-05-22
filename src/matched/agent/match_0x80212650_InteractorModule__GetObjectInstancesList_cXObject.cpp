// 0x80212650 InteractorModule::GetObjectInstancesList(cXObject (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; mr 3,29; bl _s80212650_0; cmpwi 31,0; beq 4f; lwz 9,0x4(31); lha 3,0x390(9); lwz 0,0x394(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 3f; lwz 3,0x0(31); li 4,3; bl _s80212650_1; mr 30,3; lwz 9,0x4(30); lha 3,0x40(9); lwz 0,0x44(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lwz 3,0x0(31); lwz 9,0x18(3); lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; blrl; mr. 4,3; beq 4f; mr 3,29; bl _s80212650_2; b 4f; 0:; lwz 9,0x4(30); lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; blrl; mr. 30,3; beq 4f; 1:; lwz 9,0x0(30); lwz 10,0x0(9); lwz 11,0x18(10); lha 3,0x98(11); lwz 0,0x9c(11); add 3,10,3; mtspr 8,0; blrl; mr 31,3; mr 3,29; mr 4,31; bl _s80212650_3; cmpwi 31,0; beq 2f; cmpwi 3,0; bne 2f; mr 4,31; mr 3,29; bl _s80212650_4; 2:; lwz 9,0x4(30); lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; mr. 30,3; bne 1b; b 4f; 3:; lwz 3,0x0(31); lwz 9,0x18(3); lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; blrl; mr. 4,3; beq 4f; mr 3,29; bl _s80212650_5; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80212650_0();
extern "C" void _s80212650_1();
extern "C" void _s80212650_2();
extern "C" void _s80212650_3();
extern "C" void _s80212650_4();
extern "C" void _s80212650_5();
extern "C" void f_80212650() {}
