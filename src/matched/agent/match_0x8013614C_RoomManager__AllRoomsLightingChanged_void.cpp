// 0x8013614C RoomManager::AllRoomsLightingChanged(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); li 0,0; mr 31,3; stw 0,0x8(1); li 30,1; lwz 9,0x4(31); lwz 0,0x8(9); stw 0,0x8(1); stw 0,0x10(1); b 2f; 0:; lwz 9,0x14(9); lwz 0,0x34(9); cmpwi 0,0; beq 1f; stw 30,0x84(9); 1:; lwz 3,0x8(1); bl _s8013614C_0; stw 3,0x8(1); 2:; lwz 0,0x4(31); li 11,1; lwz 9,0x8(1); stw 0,0x10(1); cmpw 9,0; bne 3f; li 11,0; 3:; cmpwi 11,0; bne 0b; li 0,1; stw 0,0x20(31); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s8013614C_0();
extern "C" void f_8013614C() {}
