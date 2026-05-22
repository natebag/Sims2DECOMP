// 0x8005FB50 SAnimator2::followStandToTurnUpdate(float (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 29,0xc(1); stw 0,0x24(1); mr 29,5; lis 9,-32707; lfs f13,0x0(29); mr 31,3; lfs f0,0x4738(9); mr 30,4; fmr f31,f1; li 3,1; fcmpu 0,f13,f0; beq 1f; lwz 0,0x61c(31); andi. 9,0,64; bne 0f; fmr f1,f13; mr 3,31; bl _s8005FB50_0; 0:; lfs f2,0x0(30); mr 3,31; lfs f3,0x0(29); fmr f1,f31; bl _s8005FB50_1; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0xc(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s8005FB50_0();
extern "C" void _s8005FB50_1();
extern "C" void f_8005FB50() {}
