// 0x8015A4E4 cXMTObject::CAST_IMPL(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 8,0; add 3,27,3; blrl; mr 3,27; bl _s8015A4E4_0; lwz 9,0xc(27); lha 3,0x48(9); lwz 0,0x4c(9); add 3,27,3; mtspr 8,0; blrl; li 3,1; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8015A4E4_0();
extern "C" int f_8015A4E4() {}
