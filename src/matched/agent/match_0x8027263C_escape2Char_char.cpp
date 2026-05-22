// 0x8027263C _escape2Char(char, (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lis 9,-32704; addi 9,9,-935; lbzx 0,3,9; andi. 0,0,68; cmpwi 0,0; beq 0f; li 0,0; stb 3,0x8(1); stb 4,0x9(1); addi 3,1,8; stb 0,0xa(1); li 4,0; li 5,16; bl _s8027263C_0; extsb 3,3; b 1f; 0:; mr 3,4; 1:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8027263C_0();
extern "C" void f_8027263C() {}
