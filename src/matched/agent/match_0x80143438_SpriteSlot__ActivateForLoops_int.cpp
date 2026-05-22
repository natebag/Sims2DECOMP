// 0x80143438 SpriteSlot::ActivateForLoops(int) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x2c(3); mulli 0,0,12; mullw 4,0,4; bl _s80143438_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80143438_0();
extern "C" void f_80143438() {}
