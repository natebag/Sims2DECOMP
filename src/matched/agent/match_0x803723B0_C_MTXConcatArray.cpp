// 0x803723B0 C_MTXConcatArray (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stmw 27,0x1c(1); mr 27,3; mr 28,4; mr 29,5; mr 30,6; li 31,0; b 0f; 0:; b 1f; 1:; b 3f; 2:; mr 3,27; mr 4,28; mr 5,29; bl _s803723B0_0; addi 28,28,48; addi 29,29,48; addi 31,31,1; 3:; cmplw 31,30; blt 2b; lmw 27,0x1c(1); lwz 0,0x34(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s803723B0_0();
extern "C" void f_803723B0() {}
