// 0x8001699C ESimsCam::GetFov(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8001699C_0; lwz 11,0x0(30); lis 9,-32707; lfs f13,-7396(9); lfs f0,0x60(11); fsubs f13,f13,f1; lfs f12,0x64(11); fmuls f0,f0,f13; fmadds f1,f12,f1,f0; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8001699C_0();
extern "C" void f_8001699C() {}
