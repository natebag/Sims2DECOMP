// 0x801370D4 RoomManager::ResetRoomManager(void) (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 28,0x38(1); stw 0,0x4c(1); mr 31,3; lwz 0,0x8(31); cmpwi 0,0; beq 5f; lwz 11,0x4(31); li 0,0; stw 0,0x8(1); lwz 9,0x8(11); stw 9,0x8(1); stw 9,0x10(1); addi 29,1,24; addi 28,1,40; b 2f; 0:; lwz 3,0x14(3); cmpwi 3,0; beq 1f; li 4,3; bl _s801370D4_0; 1:; lwz 3,0x8(1); bl _s801370D4_1; stw 3,0x8(1); 2:; lwz 0,0x4(31); li 30,1; lwz 3,0x8(1); stw 0,0x10(1); cmpw 3,0; bne 3f; li 30,0; 3:; cmpwi 30,0; bne 0b; stw 30,0x1c(1); li 3,24; bl _s801370D4_2; stw 3,0x1c(1); stw 30,0x8(29); stb 30,0x24(1); lwz 9,0x1c(1); stw 30,0x0(9); lwz 11,0x1c(1); stw 30,0x4(11); lwz 9,0x1c(1); stw 9,0x8(9); lwz 11,0x1c(1); stw 11,0xc(11); lwz 0,0x1c(1); lwz 6,0x8(31); lwz 5,0x4(31); stw 0,0x4(28); cmpwi 6,0; lbz 0,0x24(1); lwz 10,0x0(31); lwz 7,0x20(1); lbz 8,0xc(31); lwz 9,0x28(1); lwz 11,0x2c(1); stb 0,0xc(31); stw 10,0x18(1); stw 9,0x0(31); stw 11,0x4(31); stw 7,0x8(31); stb 8,0x24(1); stw 5,0x1c(1); stw 6,0x20(1); beq 4f; lwz 4,0x4(5); mr 3,29; bl _s801370D4_3; lwz 9,0x1c(1); stw 9,0x8(9); lwz 11,0x1c(1); stw 30,0x4(11); lwz 9,0x1c(1); stw 9,0xc(9); stw 30,0x8(29); 4:; lwz 3,0x1c(1); cmpwi 3,0; beq 5f; li 4,24; bl _s801370D4_4; 5:; lwz 0,0x4c(1); mtspr 8,0; lmw 28,0x38(1); addi 1,1,72"
extern "C" void _s801370D4_0();
extern "C" void _s801370D4_1();
extern "C" void _s801370D4_2();
extern "C" void _s801370D4_3();
extern "C" void _s801370D4_4();
extern "C" void f_801370D4() {}
