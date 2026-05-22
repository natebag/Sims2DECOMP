// 0x802F9E0C EShader::Clone(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,-26392(13); mr 31,3; mr 4,31; lwz 11,0x0(9); lha 3,0x108(11); lwz 0,0x10c(11); add 3,9,3; mtspr 8,0; blrl; mr. 11,3; beq 0f; lwz 9,0xe4(31); mr 3,11; stw 9,0xe4(11); lbz 0,0xec(31); stb 0,0xec(11); lbz 9,0xed(31); stb 9,0xed(11); lhz 0,0xee(31); sth 0,0xee(11); b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_802F9E0C() {}
