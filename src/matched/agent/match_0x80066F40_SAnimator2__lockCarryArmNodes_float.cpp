// 0x80066F40 SAnimator2::lockCarryArmNodes(float (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x8(3); mr 11,4; mr 4,5; lwz 9,0x358(9); cmpwi 9,0; lwz 3,0x8(3); mr 5,11; addi 3,3,820; bl _s80066F40_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80066F40_0();
extern "C" void f_80066F40() {}
