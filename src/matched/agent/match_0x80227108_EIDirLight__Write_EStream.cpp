// 0x80227108 EIDirLight::Write(EStream (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; bl _s80227108_0; mr 3,30; addi 4,29,172; bl _s80227108_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80227108_0();
extern "C" void _s80227108_1();
extern "C" void f_80227108() {}
