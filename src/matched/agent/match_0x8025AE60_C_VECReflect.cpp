// 0x8025AE60 C_VECReflect (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-56(1); stw 31,0x34(1); stw 30,0x30(1); mr 30,4; mr 31,5; lfs f0,0x0(3); fneg f0,f0; stfs f0,0x20(1); lfs f0,0x4(3); fneg f0,f0; stfs f0,0x24(1); lfs f0,0x8(3); addi 3,1,32; mr 4,3; fneg f0,f0; stfs f0,0x28(1); bl _s8025AE60_0; mr 3,30; addi 4,1,20; bl _s8025AE60_1; addi 3,1,32; addi 4,1,20; bl _s8025AE60_2; lfs f3,-18476(13); mr 3,31; lfs f2,0x14(1); mr 4,31; lfs f0,0x20(1); fmuls f2,f3,f2; fmuls f2,f2,f1; fsubs f0,f2,f0; stfs f0,0x0(31); lfs f2,0x18(1); lfs f0,0x24(1); fmuls f2,f3,f2; fmuls f2,f2,f1; fsubs f0,f2,f0; stfs f0,0x4(31); lfs f2,0x1c(1); lfs f0,0x28(1); fmuls f2,f3,f2; fmuls f1,f2,f1; fsubs f0,f1,f0; stfs f0,0x8(31); bl _s8025AE60_3; lwz 0,0x3c(1); lwz 31,0x34(1); lwz 30,0x30(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s8025AE60_0();
extern "C" void _s8025AE60_1();
extern "C" void _s8025AE60_2();
extern "C" void _s8025AE60_3();
extern "C" void f_8025AE60() {}
