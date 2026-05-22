// 0x8039F700 TArray<EILight (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 31,0x4(29); lwz 30,0x0(29); b 1f; 0:; lwz 11,0x0(30); addi 30,30,4; cmpwi 11,0; beq 1f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 1:; cmpwi 31,0; addi 31,31,-1; bne 0b; mr 3,29; bl _s8039F700_0; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8039F700_0();
extern "C" void f_8039F700() {}
