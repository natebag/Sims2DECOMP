// 0x802DF1D8 MaxisDbgTraceBinary(void (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-304(1); mfspr 0,8; stmw 29,0x124(1); stw 0,0x134(1); lis 9,-32702; addi 11,1,264; lwz 7,-6484(9); mr 29,11; addi 9,9,-6484; mr 30,3; lbz 6,0x10(9); mr. 31,4; lwz 8,0x4(9); lwz 10,0x8(9); lwz 0,0xc(9); stw 7,0x108(1); stw 8,0x4(11); stw 10,0x8(11); stw 0,0xc(11); stb 6,0x10(11); beq 4f; 0:; addi 3,1,8; li 4,0; li 5,256; bl _s802DF1D8_0; addi 8,1,8; mtspr 9,31; cmplwi 31,85; ble 1f; li 0,85; mtspr 9,0; 1:; mfspr 0,9; lis 3,-32702; cmpwi 0,0; beq 3f; mr 10,29; li 7,32; 2:; lbz 11,0x0(30); addi 31,31,-1; addi 30,30,1; rlwinm 9,11,28,4,31; lbzx 0,10,9; rlwinm 11,11,0,28,31; stb 0,0x0(8); lbzx 9,10,11; stbu 9,0x1(8); stbu 7,0x1(8); addi 8,8,1; bdnz 2b; 3:; addi 3,3,-6464; addi 4,1,8; crxor 6,6,6; bl _s802DF1D8_1; cmpwi 31,0; bne 0b; 4:; lwz 0,0x134(1); mtspr 8,0; lmw 29,0x124(1); addi 1,1,304"
extern "C" void _s802DF1D8_0();
extern "C" void _s802DF1D8_1();
extern "C" void f_802DF1D8() {}
