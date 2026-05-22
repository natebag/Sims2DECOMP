// 0x800EAFC0 cXObjectImpl::EnableSim(bool) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0x58(3); mr 6,4; lha 4,0x64(3); li 5,1; lwz 9,0x0(11); lha 3,0x240(9); lwz 0,0x244(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_800EAFC0() {}
