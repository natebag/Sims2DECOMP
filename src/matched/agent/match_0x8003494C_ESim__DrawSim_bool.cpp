// 0x8003494C ESim::DrawSim(bool) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 3,0x3d0(31); lwz 9,0x4(3); lha 0,0x238(9); lwz 9,0x23c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; li 0,0; bne 0f; mr 0,30; 0:; stw 0,0x428(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_8003494C() {}
