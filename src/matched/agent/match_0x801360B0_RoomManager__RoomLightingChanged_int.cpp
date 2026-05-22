// 0x801360B0 RoomManager::RoomLightingChanged(int) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); sth 4,0x10(1); lwz 11,0x4(3); lwz 9,0x4(11); cmpwi 9,0; beq 3f; rlwinm 4,4,0,16,31; 0:; lhz 0,0x10(9); cmplw 0,4; blt 1f; mr 11,9; lwz 9,0x8(11); b 2f; 1:; lwz 9,0xc(9); 2:; cmpwi 9,0; bne 0b; 3:; lwz 10,0x4(3); cmpw 11,10; beq 4f; lhz 9,0x10(1); lhz 0,0x10(11); cmplw 9,0; bge 5f; 4:; mr 11,10; 5:; lwz 0,0x4(3); li 9,1; stw 11,0x8(1); cmpw 11,0; stw 0,0x18(1); bne 6f; li 9,0; 6:; cmpwi 9,0; beq 7f; lwz 9,0x14(11); li 0,1; stw 0,0x84(9); stw 0,0x20(3); 7:; addi 1,1,32"
extern "C" void f_801360B0() {}
