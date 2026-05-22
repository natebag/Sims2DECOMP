// 0x802FA9AC EShader::SelectForShadowMask(ERC (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0xf0(3); li 5,0; lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_802FA9AC() {}
