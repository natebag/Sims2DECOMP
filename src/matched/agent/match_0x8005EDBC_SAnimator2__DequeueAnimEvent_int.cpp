// 0x8005EDBC SAnimator2::DequeueAnimEvent(int (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); addi 31,3,220; lwz 9,0xdc(3); lwz 0,0x4(31); li 11,0; subf 0,9,0; rlwinm. 10,0,30,2,31; beq 1f; lwz 0,0x0(9); stw 0,0x0(4); lwz 3,0xdc(3); lwz 30,0x4(31); addi 4,3,4; cmpw 30,4; beq 0f; subf 30,4,30; mr 5,30; bl _s8005EDBC_0; add 3,3,30; 0:; stw 3,0x4(31); li 11,1; 1:; mr 3,11; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8005EDBC_0();
extern "C" void f_8005EDBC() {}
