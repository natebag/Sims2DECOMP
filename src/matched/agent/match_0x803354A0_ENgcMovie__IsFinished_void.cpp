// 0x803354A0 ENgcMovie::IsFinished(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,-26348(13); mr 31,3; cmpwi 0,0; bne 0f; bl _s803354A0_0; cmpwi 3,1; beq 0f; mr 3,31; bl _s803354A0_1; cmpwi 3,2; bne 1f; 0:; li 3,0; b 2f; 1:; li 3,1; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s803354A0_0();
extern "C" void _s803354A0_1();
extern "C" void f_803354A0() {}
