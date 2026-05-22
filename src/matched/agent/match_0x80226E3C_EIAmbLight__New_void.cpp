// 0x80226E3C EIAmbLight::New(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 3,172; bl _s80226E3C_0; mr 30,3; bl _s80226E3C_1; lis 9,-32697; mr 3,30; addi 9,9,-30368; stw 9,0x0(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80226E3C_0();
extern "C" void _s80226E3C_1();
extern "C" void f_80226E3C() {}
