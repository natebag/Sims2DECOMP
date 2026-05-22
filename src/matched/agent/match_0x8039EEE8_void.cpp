// 0x8039EEE8 void (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr 30,4; mr 29,5; cmpw 31,30; beq 2f; lwz 9,0x0(29); subf 0,31,30; srawi 0,0,2; li 6,0; stw 9,0x8(1); cmpwi 0,1; beq 1f; 0:; srawi 0,0,1; addi 6,6,1; cmpwi 0,1; bne 0b; 1:; mr 3,31; mr 4,30; li 5,0; rlwinm 6,6,1,0,30; addi 7,1,8; bl _s8039EEE8_0; lwz 0,0x0(29); mr 3,31; mr 4,30; addi 5,1,8; stw 0,0x8(1); bl _s8039EEE8_1; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8039EEE8_0();
extern "C" void _s8039EEE8_1();
extern "C" void f_8039EEE8() {}
