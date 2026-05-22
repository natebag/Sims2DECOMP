// 0x80034F78 ESimShadow::ESimShadow(cXPerson (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s80034F78_0; lis 9,-32698; stw 29,0x320(30); addi 9,9,-19208; mr 3,30; stw 9,0x0(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80034F78_0();
extern "C" void f_80034F78() {}
