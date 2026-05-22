// 0x8025AD88 C_VECHalfAngle (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-64(1); stw 31,0x3c(1); mr 31,5; lfs f0,0x0(3); fneg f0,f0; stfs f0,0x2c(1); lfs f0,0x4(3); fneg f0,f0; stfs f0,0x30(1); lfs f0,0x8(3); addi 3,1,44; fneg f0,f0; stfs f0,0x34(1); lfs f0,0x0(4); fneg f0,f0; stfs f0,0x20(1); lfs f0,0x4(4); fneg f0,f0; stfs f0,0x24(1); lfs f0,0x8(4); mr 4,3; fneg f0,f0; stfs f0,0x28(1); bl _s8025AD88_0; addi 3,1,32; mr 4,3; bl _s8025AD88_1; addi 3,1,44; addi 4,1,32; addi 5,1,20; bl _s8025AD88_2; addi 3,1,20; mr 4,3; bl _s8025AD88_3; lfs f0,-18512(13); fcmpo f0,f1,f0; ble 0f; addi 3,1,20; mr 4,31; bl _s8025AD88_4; b 1f; 0:; lwz 3,0x14(1); lwz 0,0x18(1); stw 3,0x0(31); stw 0,0x4(31); lwz 0,0x1c(1); stw 0,0x8(31); 1:; lwz 0,0x44(1); lwz 31,0x3c(1); addi 1,1,64; mtspr 8,0"
extern "C" void _s8025AD88_0();
extern "C" void _s8025AD88_1();
extern "C" void _s8025AD88_2();
extern "C" void _s8025AD88_3();
extern "C" void _s8025AD88_4();
extern "C" void f_8025AD88() {}
