// 0x801383B4 Room::IsTileInRoom(CTilePt (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); addi 30,3,4; lwz 31,0x4(3); lwz 0,0x4(30); mr 29,4; cmpw 31,0; beq 2f; 0:; mr 3,31; mr 4,29; bl _s801383B4_0; cmpwi 3,0; beq 1f; li 3,1; b 3f; 1:; lwz 0,0x4(30); addi 31,31,3; cmpw 31,0; bne 0b; 2:; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801383B4_0();
extern "C" void f_801383B4() {}
