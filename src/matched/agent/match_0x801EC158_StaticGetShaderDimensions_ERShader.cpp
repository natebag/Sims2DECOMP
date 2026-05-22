// 0x801EC158 StaticGetShaderDimensions(ERShader (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,5; mr. 31,3; beq 3f; lwz 0,0x14(31); mr 3,0; cmpwi 0,0; bne 0f; lwz 9,0x18(31); li 0,0; cmpwi 9,0; beq 0f; lwz 0,0x14(9); 0:; cmpwi 0,0; beq 3f; cmpwi 3,0; beq 1f; mr 0,3; b 2f; 1:; lwz 9,0x18(31); li 0,0; cmpwi 9,0; beq 2f; lwz 0,0x14(9); 2:; mr 3,0; li 4,0; bl _s801EC158_0; cmpwi 3,0; bne 4f; 3:; li 3,0; b 7f; 4:; lwz 3,0x14(31); cmpwi 3,0; bne 5f; lwz 9,0x18(31); li 3,0; cmpwi 9,0; beq 5f; lwz 3,0x14(9); 5:; li 4,0; bl _s801EC158_1; lhz 0,0x10(3); stw 0,0x0(30); lwz 3,0x14(31); cmpwi 3,0; bne 6f; lwz 9,0x18(31); li 3,0; cmpwi 9,0; beq 6f; lwz 3,0x14(9); 6:; li 4,0; bl _s801EC158_2; lhz 0,0x12(3); li 3,1; stw 0,0x0(29); 7:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801EC158_0();
extern "C" void _s801EC158_1();
extern "C" void _s801EC158_2();
extern "C" void f_801EC158() {}
