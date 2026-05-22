// 0x80137034 RoomManager::ClearRoomPartitions(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); li 0,0; mr 31,3; stw 0,0x8(1); lwz 9,0x4(31); lwz 0,0x8(9); stw 0,0x8(1); stw 0,0x10(1); b 3f; 0:; lwz 9,0x14(9); lwz 0,0x24(9); addi 9,9,36; lwz 10,0x4(9); mr 11,0; cmpw 0,10; beq 2f; 1:; addi 11,11,20; cmpw 11,10; bne 1b; 2:; stw 0,0x4(9); lwz 3,0x8(1); bl _s80137034_0; stw 3,0x8(1); 3:; lwz 0,0x4(31); li 11,1; lwz 9,0x8(1); stw 0,0x10(1); cmpw 9,0; bne 4f; li 11,0; 4:; cmpwi 11,0; bne 0b; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s80137034_0();
extern "C" void f_80137034() {}
