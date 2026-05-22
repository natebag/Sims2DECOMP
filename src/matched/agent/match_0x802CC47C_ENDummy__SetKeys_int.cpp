// 0x802CC47C ENDummy::SetKeys(int) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; mr 0,4; addi 3,9,72; stw 0,0x44(9); li 5,0; bl _s802CC47C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802CC47C_0();
extern "C" void f_802CC47C() {}
