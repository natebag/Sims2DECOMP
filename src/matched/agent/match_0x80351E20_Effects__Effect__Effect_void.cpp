// 0x80351E20 Effects::Effect::Effect(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 30,3; li 0,0; addi 9,9,-10728; li 11,0; stw 9,0x144(30); sth 11,0x40(30); stw 0,0x4c(30); stw 0,0x44(30); stw 0,0x48(30); bl _s80351E20_0; mr 3,30; bl _s80351E20_1; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80351E20_0();
extern "C" void _s80351E20_1();
extern "C" void f_80351E20() {}
