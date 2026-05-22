// 0x8031C904 ERShader::DelRefSubResources(void) (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; bl _s8031C904_0; mr 3,30; bl _s8031C904_1; lwz 0,0x58(30); andi. 8,0,2; beq 2f; lwz 3,0x18(30); cmpwi 3,0; beq 0f; bl _s8031C904_2; li 0,0; stw 0,0x18(30); 0:; li 8,2; li 0,0; mtspr 9,8; stb 0,0x50(30); stb 0,0x64(30); addi 10,30,40; addi 11,30,32; li 0,0; li 9,0; 1:; stwx 0,9,11; stwx 0,9,10; addi 9,9,4; bdnz 1b; b 8f; 2:; addi 28,30,32; li 26,0; addi 31,30,40; li 29,0; li 27,2; 3:; lwzx 9,29,28; cmpwi 9,0; beq 5f; lwz 0,0x4(30); cmpwi 0,0; beq 4f; lwz 0,0x0(31); cmpwi 0,0; beq 5f; 4:; lha 0,0xc(9); cmpwi 0,0; beq 5f; lwz 0,0x8(9); stw 0,0x0(31); lwzx 3,29,28; bl _s8031C904_3; stwx 26,29,28; 5:; addi 31,31,4; addi 29,29,4; addic. 27,27,-1; bne 3b; lwz 0,0x30(30); li 29,0; cmplw 29,0; bge 8f; li 28,0; 6:; lwz 9,0x34(30); rlwinm 31,29,2,0,29; lwzx 9,31,9; cmpwi 9,0; beq 7f; lwz 0,0x8(9); lwz 9,0x38(30); stwx 0,31,9; lwz 11,0x34(30); lwzx 3,31,11; bl _s8031C904_4; lwz 9,0x34(30); stwx 28,31,9; 7:; addi 0,29,1; lwz 9,0x30(30); rlwinm 29,0,0,24,31; cmplw 29,9; blt 6b; 8:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8031C904_0();
extern "C" void _s8031C904_1();
extern "C" void _s8031C904_2();
extern "C" void _s8031C904_3();
extern "C" void _s8031C904_4();
extern "C" void f_8031C904() {}
