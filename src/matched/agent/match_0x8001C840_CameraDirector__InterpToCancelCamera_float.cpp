// 0x8001C840 CameraDirector::InterpToCancelCamera(float, (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 29,0xc(1); stw 0,0x24(1); mr 31,3; fmr f31,f1; lwz 0,0x170(31); mr 30,4; mr 29,5; cmpwi 0,0; beq 0f; lwz 0,0x240(31); xori 0,0,1; andi. 9,0,1; bne 1f; 0:; li 3,0; b 2f; 1:; mr 3,31; bl _s8001C840_0; stw 29,0x23c(31); fmr f1,f31; mr 4,30; mr 3,31; bl _s8001C840_1; lis 9,-32707; mr 3,31; lfs f0,-6796(9); stfs f0,0x22c(31); bl _s8001C840_2; li 3,1; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0xc(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s8001C840_0();
extern "C" void _s8001C840_1();
extern "C" void _s8001C840_2();
extern "C" void f_8001C840() {}
