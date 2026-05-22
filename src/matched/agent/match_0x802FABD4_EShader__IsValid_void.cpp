// 0x802FABD4 EShader::IsValid(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xe4(3); lis 0,-28659; ori 0,0,48879; xor 3,3,0; subfic 0,3,0; adde 3,0,3"
extern "C" int f_802FABD4() {}
