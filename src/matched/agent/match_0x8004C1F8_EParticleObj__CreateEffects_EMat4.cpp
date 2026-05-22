// 0x8004C1F8 EParticleObj::CreateEffects(EMat4 (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 27,4; lwz 9,0x4(29); mr 30,5; b 2f; 0:; lwz 0,0x8(29); lwz 3,0x0(9); cmpwi 0,0; lwz 31,0x4(9); beq 1f; cmpwi 3,0; beq 1f; li 4,3; bl _s8004C1F8_0; 1:; mr 9,31; 2:; li 31,1; cmpwi 9,0; bne 3f; li 31,0; 3:; cmpwi 31,0; bne 0b; mr 3,29; bl _s8004C1F8_1; lwz 3,0xc(29); cmpwi 3,0; beq 4f; bl _s8004C1F8_2; stw 31,0xc(29); 4:; lwz 4,0x4(30); cmpwi 4,0; li 3,0; beq 10f; lis 3,-32692; li 5,0; addi 3,3,-4004; li 6,0; bl _s8004C1F8_3; stw 3,0xc(29); cmpwi 3,0; bne 5f; li 3,0; b 10f; 5:; lwz 0,0x18(3); lwz 9,0x14(3); subf 0,9,0; srawi. 31,0,3; bne 6f; bl _s8004C1F8_4; stw 31,0xc(29); li 3,0; b 10f; 6:; cmpwi 31,0; ble 9f; mr 30,31; li 28,0; 7:; lwz 9,0xc(29); lwz 0,0x14(9); add 31,0,28; lwz 9,0x4(31); cmpwi 9,0; beq 8f; bl _s8004C1F8_5; li 7,0; li 4,112; li 5,16; li 6,0; bl _s8004C1F8_6; mr 4,31; mr 5,27; bl _s8004C1F8_7; mr 4,3; mr 3,29; bl _s8004C1F8_8; 8:; addi 28,28,8; addic. 30,30,-1; bne 7b; 9:; li 3,1; 10:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8004C1F8_0();
extern "C" void _s8004C1F8_1();
extern "C" void _s8004C1F8_2();
extern "C" void _s8004C1F8_3();
extern "C" void _s8004C1F8_4();
extern "C" void _s8004C1F8_5();
extern "C" void _s8004C1F8_6();
extern "C" void _s8004C1F8_7();
extern "C" void _s8004C1F8_8();
extern "C" void f_8004C1F8() {}
