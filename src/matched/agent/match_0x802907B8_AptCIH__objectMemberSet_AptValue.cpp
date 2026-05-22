// 0x802907B8 AptCIH::objectMemberSet(AptValue (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 3,4; mr 4,5; mr 5,6; bl _s802907B8_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802907B8_0();
extern "C" void f_802907B8() {}
