// 0x80173B54 CasSimState::GetNextAvailableSleeveStyle(eBodyPartS2C, (776 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 23,0x2c(1); stw 0,0x54(1); mr 28,4; mr 24,3; mr 25,5; mr 23,6; mr 26,7; addi 3,1,8; addi 4,24,8; mr 5,28; bl _s80173B54_0; cmpwi 28,11; beq 5f; bgt 0f; cmpwi 28,8; beq 1f; b 14f; 0:; cmpwi 28,14; beq 9f; b 14f; 1:; lwz 27,0x10(1); mr 3,24; li 4,8; mr 6,23; mr 5,27; bl _s80173B54_1; mr 31,3; cmpw 27,31; beq 13f; addi 30,1,24; addi 29,1,8; 2:; stw 31,0x10(1); cmpwi 31,0; bne 3f; lwz 10,0x8(1); mr 3,26; lwz 11,0x4(29); li 4,8; lwz 9,0x8(29); mr 5,25; lwz 0,0xc(29); mr 6,30; stw 10,0x18(1); stw 11,0x4(30); stw 9,0x8(30); stw 0,0xc(30); bl _s80173B54_2; cmpwi 3,0; beq 4f; b 14f; 3:; lwz 10,0x8(1); mr 3,26; lwz 11,0x4(29); mr 4,28; lwz 9,0x8(29); mr 5,25; lwz 0,0xc(29); mr 6,30; stw 10,0x18(1); stw 11,0x4(30); stw 9,0x8(30); stw 0,0xc(30); bl _s80173B54_3; cmpwi 3,0; mr 3,31; bne 15f; 4:; mr 5,31; mr 3,24; mr 4,28; mr 6,23; bl _s80173B54_4; mr 31,3; cmpw 27,31; bne 2b; b 13f; 5:; lwz 27,0x14(1); mr 3,24; li 4,11; mr 6,23; mr 5,27; bl _s80173B54_5; mr 31,3; cmpw 27,31; beq 13f; addi 30,1,24; addi 29,1,8; 6:; stw 31,0x14(1); cmpwi 31,0; bne 7f; lwz 10,0x8(1); mr 3,26; lwz 11,0x4(29); li 4,11; lwz 9,0x8(29); mr 5,25; lwz 0,0xc(29); mr 6,30; stw 10,0x18(1); stw 11,0x4(30); stw 9,0x8(30); stw 0,0xc(30); bl _s80173B54_6; cmpwi 3,0; beq 8f; b 14f; 7:; lwz 10,0x8(1); mr 3,26; lwz 11,0x4(29); mr 4,28; lwz 9,0x8(29); mr 5,25; lwz 0,0xc(29); mr 6,30; stw 10,0x18(1); stw 11,0x4(30); stw 9,0x8(30); stw 0,0xc(30); bl _s80173B54_7; cmpwi 3,0; mr 3,31; bne 15f; 8:; mr 5,31; mr 3,24; mr 4,28; mr 6,23; bl _s80173B54_8; mr 31,3; cmpw 27,31; bne 6b; b 13f; 9:; lwz 27,0x14(1); mr 3,24; li 4,14; mr 6,23; mr 5,27; bl _s80173B54_9; mr 31,3; cmpw 27,31; beq 13f; addi 30,1,24; addi 29,1,8; 10:; stw 31,0x14(1); cmpwi 31,0; bne 11f; lwz 10,0x8(1); mr 3,26; lwz 11,0x4(29); li 4,14; lwz 9,0x8(29); mr 5,25; lwz 0,0xc(29); mr 6,30; stw 10,0x18(1); stw 11,0x4(30); stw 9,0x8(30); stw 0,0xc(30); bl _s80173B54_10; cmpwi 3,0; beq 12f; b 14f; 11:; lwz 10,0x8(1); mr 3,26; lwz 11,0x4(29); mr 4,28; lwz 9,0x8(29); mr 5,25; lwz 0,0xc(29); mr 6,30; stw 10,0x18(1); stw 11,0x4(30); stw 9,0x8(30); stw 0,0xc(30); bl _s80173B54_11; cmpwi 3,0; mr 3,31; bne 15f; 12:; mr 5,31; mr 3,24; mr 4,28; mr 6,23; bl _s80173B54_12; mr 31,3; cmpw 27,31; bne 10b; 13:; mr 3,31; b 15f; 14:; li 3,0; 15:; lwz 0,0x54(1); mtspr 8,0; lmw 23,0x2c(1); addi 1,1,80"
extern "C" void _s80173B54_0();
extern "C" void _s80173B54_1();
extern "C" void _s80173B54_2();
extern "C" void _s80173B54_3();
extern "C" void _s80173B54_4();
extern "C" void _s80173B54_5();
extern "C" void _s80173B54_6();
extern "C" void _s80173B54_7();
extern "C" void _s80173B54_8();
extern "C" void _s80173B54_9();
extern "C" void _s80173B54_10();
extern "C" void _s80173B54_11();
extern "C" void _s80173B54_12();
extern "C" void f_80173B54() {}
