// 0x80034AF0 ESim::UpdatePlumbBob(void) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x3ec(3); addi 9,9,-3; cmpwi 9,6; bgtlr; lfs f0,0x3f4(3); lfs f13,-26800(13); fadds f0,f0,f13; stfs f0,0x3f4(3)"
extern "C" void f_80034AF0() {}
