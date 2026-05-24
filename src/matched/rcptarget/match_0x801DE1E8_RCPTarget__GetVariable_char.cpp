// 0x801DE1E8 RCPTarget::GetVariable(char (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; li 3,32; bl _s801DE1E8_0; mr. 30,3; bne 0f; li 3,0; b 6f; 0:; li 0,0; lis 3,-32705; stb 0,0x0(30); addi 3,3,20860; mr 4,29; bl _s801DE1E8_1; cmpwi 3,0; bne 3f; lwz 0,0x128(31); lis 9,-21846; ori 9,9,43691; mulhwu 9,0,9; rlwinm 9,9,31,1,31; rlwinm 11,9,1,0,30; stw 9,0x12c(31); add 11,11,9; cmpw 0,11; beq 1f; addi 0,9,1; stw 0,0x12c(31); 1:; lwz 0,0x12c(31); cmpwi 0,0; bne 2f; li 0,1; stw 0,0x12c(31); 2:; lis 4,-32705; lwz 5,0x12c(31); addi 4,4,-8800; mr 3,30; crxor 6,6,6; bl _s801DE1E8_2; b 5f; 3:; lis 3,-32705; mr 4,29; addi 3,3,20840; bl _s801DE1E8_3; cmpwi 3,0; bne 4f; lwz 5,0x118(31); lis 4,-32705; addi 4,4,-8800; mr 3,30; subfic 0,5,0; adde 5,0,5; crxor 6,6,6; bl _s801DE1E8_4; b 5f; 4:; lis 3,-32705; mr 4,29; addi 3,3,20828; bl _s801DE1E8_5; cmpwi 3,0; bne 5f; lis 9,-32705; addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(30); sth 0,0x4(30); stb 8,0x6(30); 5:; mr 3,30; bl _s801DE1E8_6; mr 3,30; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s801DE1E8_0();
extern "C" void _s801DE1E8_1();
extern "C" void _s801DE1E8_2();
extern "C" void _s801DE1E8_3();
extern "C" void _s801DE1E8_4();
extern "C" void _s801DE1E8_5();
extern "C" void _s801DE1E8_6();

struct RCPTarget {
    void GetVariable();
};

void RCPTarget::GetVariable() {
}
