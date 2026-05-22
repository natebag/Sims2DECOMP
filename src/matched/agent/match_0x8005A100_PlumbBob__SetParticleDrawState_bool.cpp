// 0x8005A100 PlumbBob::SetParticleDrawState(bool) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 28,0; lwz 0,0x1f4(30); li 29,0; cmpw 28,0; bge 1f; addi 31,30,492; 0:; lwz 3,0x0(31); li 4,2; li 5,0; addi 29,29,1; bl _s8005A100_0; addi 31,31,4; lwz 0,0x1f4(30); cmpw 29,0; blt 0b; 1:; cmpwi 28,0; beq 2f; lwz 0,0x154(30); ori 0,0,4; b 3f; 2:; lwz 0,0x154(30); rlwinm 0,0,0,30,28; 3:; stw 0,0x154(30); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8005A100_0();
extern "C" void f_8005A100() {}
