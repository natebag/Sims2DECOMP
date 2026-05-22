// 0x80135E6C RoomManager::~RoomManager(void) (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); li 0,0; mr 30,3; stw 0,0x8(1); mr 28,4; stw 0,-31676(13); lwz 9,0x4(30); lwz 0,0x8(9); stw 0,0x8(1); stw 0,0x10(1); b 2f; 0:; lwz 3,0x14(3); cmpwi 3,0; beq 1f; li 4,3; bl _s80135E6C_0; 1:; lwz 3,0x8(1); bl _s80135E6C_1; stw 3,0x8(1); 2:; lwz 9,0x4(30); li 29,1; lwz 3,0x8(1); stw 9,0x10(1); cmpw 3,9; bne 3f; li 29,0; 3:; cmpwi 29,0; bne 0b; lwz 0,0x8(30); cmpwi 0,0; beq 4f; lwz 4,0x4(9); mr 3,30; bl _s80135E6C_2; lwz 9,0x4(30); stw 9,0x8(9); lwz 11,0x4(30); stw 29,0x4(11); lwz 9,0x4(30); stw 9,0xc(9); stw 29,0x8(30); 4:; addi 31,30,16; lwz 0,0x8(31); cmpwi 0,0; beq 5f; lwz 9,0x4(31); mr 3,31; lwz 4,0x4(9); bl _s80135E6C_3; lwz 9,0x4(31); stw 9,0x8(9); lwz 11,0x4(31); stw 29,0x4(11); lwz 9,0x4(31); stw 9,0xc(9); stw 29,0x8(31); 5:; lwz 0,0x8(31); cmpwi 0,0; beq 6f; lwz 9,0x4(31); mr 3,31; lwz 4,0x4(9); bl _s80135E6C_4; lwz 9,0x4(31); stw 9,0x8(9); lwz 11,0x4(31); stw 29,0x4(11); lwz 9,0x4(31); stw 9,0xc(9); stw 29,0x8(31); 6:; lwz 3,0x4(31); cmpwi 3,0; beq 7f; li 4,36; bl _s80135E6C_5; 7:; lwz 0,0x8(30); cmpwi 0,0; beq 8f; lwz 9,0x4(30); mr 3,30; lwz 4,0x4(9); bl _s80135E6C_6; lwz 9,0x4(30); stw 9,0x8(9); lwz 11,0x4(30); stw 29,0x4(11); lwz 9,0x4(30); stw 9,0xc(9); stw 29,0x8(30); 8:; lwz 3,0x4(30); cmpwi 3,0; beq 9f; li 4,24; bl _s80135E6C_7; 9:; andi. 0,28,1; beq 10f; mr 3,30; bl _s80135E6C_8; 10:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s80135E6C_0();
extern "C" void _s80135E6C_1();
extern "C" void _s80135E6C_2();
extern "C" void _s80135E6C_3();
extern "C" void _s80135E6C_4();
extern "C" void _s80135E6C_5();
extern "C" void _s80135E6C_6();
extern "C" void _s80135E6C_7();
extern "C" void _s80135E6C_8();
extern "C" void f_80135E6C() {}
