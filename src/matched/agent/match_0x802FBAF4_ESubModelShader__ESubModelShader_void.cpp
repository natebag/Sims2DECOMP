// 0x802FBAF4 ESubModelShader::ESubModelShader(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; li 29,0; addi 3,30,20; bl _s802FBAF4_0; addi 3,30,44; bl _s802FBAF4_1; lis 9,-32702; stw 29,0x0(30); lfs f0,-2748(9); addi 3,30,56; stw 29,0x8(30); li 4,0; stw 29,0x10(30); li 5,48; stw 29,0xc(30); stw 29,0x28(30); stfs f0,0x24(30); bl _s802FBAF4_2; stw 29,0x4(30); mr 3,30; stw 29,0x68(30); stw 29,0x6c(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802FBAF4_0();
extern "C" void _s802FBAF4_1();
extern "C" void _s802FBAF4_2();
extern "C" void f_802FBAF4() {}
