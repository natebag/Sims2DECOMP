// 0x802F1748 EGraphics::CreateShader(EShaderDef (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 9,0x0(30); lha 3,0x1f8(9); lwz 0,0x1fc(9); add 3,30,3; mtspr 8,0; blrl; mr. 31,3; beq 1f; lwz 9,0x38(30); mr 4,29; addi 9,9,1; stw 9,0x38(30); lwz 11,0xf0(31); lha 3,0x20(11); lwz 0,0x24(11); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; mr 3,31; b 2f; 0:; lwz 9,0x0(30); mr 4,31; lha 3,0x110(9); lwz 0,0x114(9); add 3,30,3; mtspr 8,0; blrl; 1:; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_802F1748() {}
