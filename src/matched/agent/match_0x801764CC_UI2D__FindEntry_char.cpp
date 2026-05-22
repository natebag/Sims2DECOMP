// 0x801764CC UI2D::FindEntry(char (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; lwz 31,0x0(29); b 1f; 0:; lwz 31,0x4(31); 1:; cmpwi 31,0; beq 5f; lwz 3,0x8(31); cmpw 3,30; beq 2f; mr 4,30; bl _s801764CC_0; cmpwi 3,0; bne 0b; 2:; lwz 0,0x0(29); cmpw 31,0; beq 5f; lwz 0,0x4(29); cmpw 31,0; bne 3f; lwz 0,0x0(31); stw 0,0x4(29); b 4f; 3:; lwz 9,0x4(31); lwz 0,0x0(31); stw 0,0x0(9); 4:; lwz 9,0x0(31); li 11,0; lwz 0,0x4(31); stw 0,0x4(9); stw 11,0x0(31); lwz 0,0x0(29); stw 0,0x4(31); lwz 9,0x0(29); stw 31,0x0(9); stw 31,0x0(29); 5:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801764CC_0();
extern "C" void f_801764CC() {}
