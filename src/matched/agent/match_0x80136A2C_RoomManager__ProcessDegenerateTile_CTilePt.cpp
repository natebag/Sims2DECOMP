// 0x80136A2C RoomManager::ProcessDegenerateTile(CTilePt (492 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 24,0x50(1); stw 0,0x74(1); mr 28,6; li 0,0; cmpwi 28,2; mr 27,4; mr 25,5; stw 0,0x8(1); li 24,0; beq 4f; bgt 0f; cmpwi 28,1; beq 1f; b 5f; 0:; cmpwi 28,3; beq 2f; cmpwi 28,4; beq 3f; b 5f; 1:; li 24,3; b 5f; 2:; li 24,1; b 5f; 3:; li 24,2; b 5f; 4:; li 24,4; 5:; addi 29,3,16; lwz 30,0x4(29); mr 26,29; lwz 31,0x4(30); 6:; cmpwi 31,0; beq 8f; addi 3,31,16; mr 4,27; bl _s80136A2C_0; cmpwi 3,0; bne 7f; mr 30,31; lwz 31,0x8(30); b 6b; 7:; lwz 31,0xc(31); b 6b; 8:; lwz 0,0x4(29); cmpw 30,0; beq 9f; mr 3,27; addi 4,30,16; bl _s80136A2C_1; cmpwi 3,0; beq 10f; 9:; lwz 30,0x4(29); 10:; lwz 5,0x4(26); stw 30,0x8(1); stw 5,0x10(1); cmpw 30,5; bne 11f; li 0,-1; sth 25,0x40(1); stw 28,0x44(1); mr 4,27; sth 0,0x48(1); addi 3,1,24; stw 24,0x4c(1); lwz 9,0x40(1); lwz 10,0x44(1); lwz 11,0x48(1); lwz 12,0x4c(1); stw 9,0x30(1); stw 10,0x34(1); stw 11,0x38(1); stw 12,0x3c(1); bl _s80136A2C_2; lwz 9,0x30(1); lwz 10,0x34(1); mr 4,26; lwz 11,0x38(1); lwz 12,0x3c(1); addi 3,1,48; stw 9,0x1c(1); stw 10,0x20(1); addi 5,1,24; stw 11,0x24(1); stw 12,0x28(1); bl _s80136A2C_3; addi 3,1,24; li 4,2; bl _s80136A2C_4; b 14f; 11:; addi 9,30,16; lhz 0,0x4(9); cmpw 0,25; bne 13f; addi 6,5,12; addi 4,5,4; addi 5,5,8; stw 30,0x18(1); stw 30,0x20(1); mr 3,30; bl _s80136A2C_5; mr 31,3; li 4,2; addi 3,31,16; bl _s80136A2C_6; cmpwi 31,0; beq 12f; mr 3,31; li 4,36; bl _s80136A2C_7; 12:; lwz 9,0x8(26); li 3,0; addi 9,9,-1; stw 9,0x8(26); b 15f; 13:; stw 28,0x10(9); sth 25,0xc(9); 14:; li 3,1; 15:; lwz 0,0x74(1); mtspr 8,0; lmw 24,0x50(1); addi 1,1,112"
extern "C" void _s80136A2C_0();
extern "C" void _s80136A2C_1();
extern "C" void _s80136A2C_2();
extern "C" void _s80136A2C_3();
extern "C" void _s80136A2C_4();
extern "C" void _s80136A2C_5();
extern "C" void _s80136A2C_6();
extern "C" void _s80136A2C_7();
extern "C" void f_80136A2C() {}
