// 0x802FA084 EShader::UpdateAll(float) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stw 31,0xc(1); stw 0,0x1c(1); lis 3,-32693; li 4,-1; lwz 9,0x8d8(3); fmr f31,f1; addi 3,3,2264; lha 0,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; lwz 31,-22720(13); cmpwi 31,0; beq 1f; 0:; lwz 3,0x0(31); fmr f1,f31; lwz 9,0xf0(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; lwz 31,0x20(31); cmpwi 31,0; bne 0b; 1:; lis 3,-32693; lwz 9,0x8d8(3); addi 3,3,2264; lha 0,0x18(9); lwz 9,0x1c(9); add 3,0,3; mtspr 8,9; blrl; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0xc(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void f_802FA084() {}
