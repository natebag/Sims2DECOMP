// 0x803204A4 ERShader::Construct(ERShader (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 4,3; li 3,108; bl _s803204A4_0; bl _s803204A4_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s803204A4_0();
extern "C" void _s803204A4_1();
extern "C" void f_803204A4() {}
