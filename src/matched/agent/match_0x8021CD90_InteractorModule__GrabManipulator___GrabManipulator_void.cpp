// 0x8021CD90 InteractorModule::GrabManipulator::~GrabManipulator(void) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32697; lis 11,-32698; addi 9,9,-31704; addi 11,11,-10560; stw 9,0x5c(3); stw 11,0xbc(3); bl _s8021CD90_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8021CD90_0();
extern "C" void f_8021CD90() {}
