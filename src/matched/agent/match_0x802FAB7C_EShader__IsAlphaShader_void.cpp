// 0x802FAB7C EShader::IsAlphaShader(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,3,100; li 9,0; lwz 0,0xc(3); andi. 11,0,64; beq 1f; lbz 0,0x1c(3); cmpwi 0,1; beq 0f; lbz 0,0x1d(3); cmpwi 0,1; beq 0f; lbz 0,0x1f(3); cmpwi 0,1; bne 1f; 0:; li 9,1; 1:; mr 3,9"
extern "C" int f_802FAB7C() {}
