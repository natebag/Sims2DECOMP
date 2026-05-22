// 0x8006634C SAnimator2::triggerCameraBloom(char (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,-21508(13); mr 31,3; lwz 11,0x0(9); lha 3,0x180(11); lwz 0,0x184(11); add 3,9,3; mtspr 8,0; blrl; mr. 4,3; beq 0f; mr 3,31; bl _s8006634C_0; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8006634C_0();
extern "C" void f_8006634C() {}
