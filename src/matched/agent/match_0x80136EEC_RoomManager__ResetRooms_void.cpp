// 0x80136EEC RoomManager::ResetRooms(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); li 0,0; mr 31,3; stw 0,0x8(1); lwz 9,0x4(31); lwz 0,0x8(9); stw 0,0x8(1); stw 0,0x10(1); b 2f; 0:; lwz 3,0x14(3); lwz 0,0x34(3); cmpwi 0,0; beq 1f; bl _s80136EEC_0; 1:; lwz 3,0x8(1); bl _s80136EEC_1; stw 3,0x8(1); 2:; lwz 0,0x4(31); li 30,1; lwz 3,0x8(1); stw 0,0x10(1); cmpw 3,0; bne 3f; li 30,0; 3:; cmpwi 30,0; bne 0b; addi 31,31,16; lwz 0,0x8(31); cmpwi 0,0; beq 4f; lwz 9,0x4(31); mr 3,31; lwz 4,0x4(9); bl _s80136EEC_2; lwz 9,0x4(31); stw 9,0x8(9); lwz 11,0x4(31); stw 30,0x4(11); lwz 9,0x4(31); stw 9,0xc(9); stw 30,0x8(31); 4:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s80136EEC_0();
extern "C" void _s80136EEC_1();
extern "C" void _s80136EEC_2();
extern "C" void f_80136EEC() {}
