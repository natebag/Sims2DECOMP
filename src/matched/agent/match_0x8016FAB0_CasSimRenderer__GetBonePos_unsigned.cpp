// 0x8016FAB0 CasSimRenderer::GetBonePos(unsigned (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 30,0x48(1); stw 0,0x54(1); mr 30,5; addi 3,3,372; addi 5,1,8; bl _s8016FAB0_0; addi 9,1,56; lwz 10,0x38(1); lwz 0,0x8(9); lwz 11,0x4(9); stw 0,0x8(30); stw 10,0x0(30); stw 11,0x4(30); lwz 0,0x54(1); mtspr 8,0; lmw 30,0x48(1); addi 1,1,80"
extern "C" void _s8016FAB0_0();
extern "C" void f_8016FAB0() {}
