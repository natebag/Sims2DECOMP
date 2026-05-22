// 0x8009D64C TArray<ENDummyPoint, (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 28,0; bl _s8009D64C_0; cmplw 31,3; bge 0f; addi 31,31,1; b 1f; 0:; mr 3,29; bl _s8009D64C_1; mr 31,3; 1:; mr 3,29; bl _s8009D64C_2; cmpwi 3,0; beq 5f; cmpwi 31,0; beq 5f; 2:; li 28,0; addi 30,31,-1; b 4f; 3:; addi 28,28,1; 4:; cmpw 28,27; beq 6f; mr 3,29; bl _s8009D64C_3; add 3,3,31; lbzx 9,26,28; lbz 0,-1(3); cmpw 0,9; bne 3b; mr. 31,30; bne 2b; 5:; cmpw 28,27; bne 7f; 6:; mr 3,29; bl _s8009D64C_4; cmpwi 3,0; addi 3,31,-1; bne 8f; 7:; li 3,-1; 8:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32; blr; lis 9,-32696; mr 10,3; addi 9,9,23952; stw 9,0x0(10); lwz 11,0xc(9); addi 11,11,1; stw 11,0xc(9)"
extern "C" void _s8009D64C_0();
extern "C" void _s8009D64C_1();
extern "C" void _s8009D64C_2();
extern "C" void _s8009D64C_3();
extern "C" void _s8009D64C_4();
extern "C" void f_8009D64C() {}
