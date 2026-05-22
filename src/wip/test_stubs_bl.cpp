// 0x80066F40 SAnimator2::lockCarryArmNodes(float,float) (64B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mflr 0; stw 0,0xc(1); lwz 9,8(3); mr 11,4; mr 4,5; lwz 9,0x358(9); cmpwi 9,0; lwz 3,8(3); mr 5,11; addi 3,3,0x334; bl _stub_bl_0; lwz 0,0xc(1); mtlr 0; addi 1,1,8"
extern "C" void _stub_bl_0();
extern "C" int f_80066F40() {}
