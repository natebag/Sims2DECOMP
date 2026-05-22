// 0x8035728C MotionBlur::EffectStateChanged(FrameEffect::EffectState) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,2; beq 0f; cmpwi 4,8; bnelr; 0:; lwz 8,0x20(3); addi 9,3,32; lwz 10,0x8(9); addi 11,3,44; lwz 0,0x4(9); stw 8,0x2c(3); stw 10,0x8(11); stw 0,0x4(11)"
extern "C" void f_8035728C() {}
