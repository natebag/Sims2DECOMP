// 0x8035A258 EBoundSphere::ComputeFast(EVec3 (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 29,0x34(1); stw 0,0x44(1); lis 9,-32702; addi 10,1,20; lfs f0,0x2c9c(9); addi 30,1,8; mr 29,3; stfs f0,0x20(1); mr 3,30; stfs f0,0x28(1); stfs f0,0x24(1); lwz 0,0x20(1); lwz 9,0x24(1); lwz 11,0x28(1); stw 0,0x14(1); stw 11,0x8(10); stw 9,0x4(10); lwz 0,0x14(1); stw 0,0x8(1); stw 9,0x4(30); stw 11,0x8(30); bl _s8035A258_0; mr 3,30; mr 4,29; bl _s8035A258_1; mr 3,29; lwz 0,0x44(1); mtspr 8,0; lmw 29,0x34(1); addi 1,1,64"
extern "C" void _s8035A258_0();
extern "C" void _s8035A258_1();
extern "C" void f_8035A258() {}
