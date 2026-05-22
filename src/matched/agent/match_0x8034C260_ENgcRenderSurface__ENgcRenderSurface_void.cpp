// 0x8034C260 ENgcRenderSurface::ENgcRenderSurface(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8034C260_0; lis 9,-32697; li 0,0; addi 9,9,-12920; stw 0,0x28(30); stw 9,0x20(30); mr 3,30; stw 0,0x24(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8034C260_0();
extern "C" void f_8034C260() {}
