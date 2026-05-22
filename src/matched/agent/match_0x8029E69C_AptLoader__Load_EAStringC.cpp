// 0x8029E69C AptLoader::Load(EAStringC (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 27,3; mr 29,4; mr 28,5; addi 3,1,8; bl _s8029E69C_0; li 30,1; lwz 3,0x8(1); cmpwi 7,3,0; bne cr7,0f; li 30,0; 0:; cmpwi 30,0; beq 2f; stw 3,0x0(27); beq cr7,1f; bl _s8029E69C_1; 1:; lwz 3,0x8(1); cmpwi 3,0; beq 6f; bl _s8029E69C_2; cmpwi 3,0; bne 6f; lwz 3,0x8(1); bl _s8029E69C_3; b 6f; 2:; lwz 3,-23020(13); li 4,24; bl _s8029E69C_4; mr 31,3; mr 4,28; stw 30,0x0(31); addi 3,31,4; bl _s8029E69C_5; li 0,1; stw 30,0xc(31); stw 0,0x8(31); cmpwi 31,0; stw 30,0x10(31); stw 30,0x14(31); stw 31,0x10(1); beq 3f; mr 3,31; bl _s8029E69C_6; 3:; lwz 3,-23020(13); li 4,8; bl _s8029E69C_7; stw 30,0x4(3); stw 31,0x0(3); lwz 0,0x0(29); stw 0,0x4(3); stw 3,0x0(29); lwz 3,0x10(1); stw 3,0x0(27); cmpwi 3,0; beq 4f; bl _s8029E69C_8; 4:; lwz 3,0x10(1); cmpwi 3,0; beq 5f; bl _s8029E69C_9; cmpwi 3,0; bne 5f; lwz 3,0x10(1); bl _s8029E69C_10; 5:; lwz 3,0x8(1); cmpwi 3,0; beq 6f; bl _s8029E69C_11; cmpwi 3,0; bne 6f; lwz 3,0x8(1); bl _s8029E69C_12; 6:; mr 3,27; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s8029E69C_0();
extern "C" void _s8029E69C_1();
extern "C" void _s8029E69C_2();
extern "C" void _s8029E69C_3();
extern "C" void _s8029E69C_4();
extern "C" void _s8029E69C_5();
extern "C" void _s8029E69C_6();
extern "C" void _s8029E69C_7();
extern "C" void _s8029E69C_8();
extern "C" void _s8029E69C_9();
extern "C" void _s8029E69C_10();
extern "C" void _s8029E69C_11();
extern "C" void _s8029E69C_12();
extern "C" void f_8029E69C() {}
