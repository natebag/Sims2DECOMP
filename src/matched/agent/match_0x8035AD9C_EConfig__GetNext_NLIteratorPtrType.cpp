// 0x8035AD9C EConfig::GetNext(NLIteratorPtrType (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 0,4; mr 4,5; mr 5,6; mr 6,0; bl _s8035AD9C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8035AD9C_0();
extern "C" void f_8035AD9C() {}
