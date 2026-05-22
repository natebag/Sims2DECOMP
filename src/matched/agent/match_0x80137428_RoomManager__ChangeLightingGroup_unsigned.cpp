// 0x80137428 RoomManager::ChangeLightingGroup(unsigned (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; mr 29,5; bl _s80137428_0; mr. 3,3; beq 4f; lhz 30,0x2(3); li 0,0; stw 0,0x8(1); lwz 9,0x4(31); lwz 0,0x8(9); stw 0,0x8(1); stw 0,0x10(1); b 2f; 0:; lwz 9,0x14(9); lhz 0,0x2(9); cmpw 0,30; bne 1f; sth 29,0x2(9); 1:; lwz 3,0x8(1); bl _s80137428_1; stw 3,0x8(1); 2:; lwz 0,0x4(31); li 11,1; lwz 9,0x8(1); stw 0,0x10(1); cmpw 9,0; bne 3f; li 11,0; 3:; cmpwi 11,0; bne 0b; 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s80137428_0();
extern "C" void _s80137428_1();
extern "C" void f_80137428() {}
