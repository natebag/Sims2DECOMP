// 0x8035A7D8 EConfig::SetInt(char (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stmw 29,0x8c(1); stw 0,0x9c(1); mr 29,4; mr 30,3; lis 4,-32702; addi 3,1,8; addi 4,4,11448; crxor 6,6,6; bl _s8035A7D8_0; mr 3,30; mr 4,29; addi 5,1,8; bl _s8035A7D8_1; lwz 0,0x9c(1); mtspr 8,0; lmw 29,0x8c(1); addi 1,1,152"
extern "C" void _s8035A7D8_0();
extern "C" void _s8035A7D8_1();
extern "C" void f_8035A7D8() {}
