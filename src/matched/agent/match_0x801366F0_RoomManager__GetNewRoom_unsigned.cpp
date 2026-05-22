// 0x801366F0 RoomManager::GetNewRoom(unsigned (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 30,0x30(1); stw 0,0x3c(1); sth 4,0x8(1); mr 31,3; addi 8,1,8; lwz 11,0x4(31); lwz 9,0x4(11); 0:; cmpwi 9,0; beq 2f; lhz 0,0x10(9); cmplw 0,4; blt 1f; mr 11,9; lwz 9,0x8(11); b 0b; 1:; lwz 9,0xc(9); b 0b; 2:; lwz 10,0x4(31); cmpw 11,10; beq 3f; lhz 9,0x0(8); lhz 0,0x10(11); cmplw 9,0; bge 4f; 3:; mr 11,10; 4:; lwz 0,0x4(31); li 9,1; stw 11,0x10(1); cmpw 11,0; stw 0,0x18(1); bne 5f; li 9,0; 5:; cmpwi 9,0; beq 6f; lwz 30,0x14(11); mr 3,30; bl _s801366F0_0; b 8f; 6:; bl _s801366F0_1; li 6,0; li 7,0; li 4,164; li 5,16; bl _s801366F0_2; lhz 4,0x8(1); mr 5,31; bl _s801366F0_3; mr. 30,3; bne 7f; li 3,0; b 9f; 7:; lhz 0,0x8(1); addi 3,1,40; mr 4,31; stw 30,0x24(1); sth 0,0x20(1); addi 5,1,32; bl _s801366F0_4; 8:; li 0,1; mr 3,30; stw 0,0x34(30); 9:; lwz 0,0x3c(1); mtspr 8,0; lmw 30,0x30(1); addi 1,1,56"
extern "C" void _s801366F0_0();
extern "C" void _s801366F0_1();
extern "C" void _s801366F0_2();
extern "C" void _s801366F0_3();
extern "C" void _s801366F0_4();
extern "C" void f_801366F0() {}
