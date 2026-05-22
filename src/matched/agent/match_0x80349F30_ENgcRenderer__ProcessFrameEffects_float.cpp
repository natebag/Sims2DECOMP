// 0x80349F30 ENgcRenderer::ProcessFrameEffects(float, (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); addi 1,1,112"
extern "C" int f_80349F30() {}
