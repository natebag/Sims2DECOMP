// 0x8031CAF8 ERShader::AddRefSubResources(void) (724 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,3; lwz 0,0x58(31); andi. 9,0,2; beq 7f; lwz 10,-26656(13); li 6,0; cmpwi 10,0; beq 2f; lwz 0,-26652(13); li 9,0; mr 7,0; cmplw 6,0; bge 1f; lwz 11,0x8(31); lwz 0,0x0(10); cmpw 11,0; beq 1f; mr 8,11; mr 11,7; 0:; addi 9,9,1; cmplw 9,11; bge 1f; lwzu 0,0x4(10); cmpw 8,0; bne 0b; 1:; cmpw 9,7; beq 2f; li 0,1; li 6,1; stb 0,0x64(31); 2:; cmpwi 6,0; beq 3f; lbz 11,0x64(31); mr 3,31; lwz 9,0x48(31); b 4f; 3:; lbz 11,-26648(13); lbz 0,0x44(31); cmplw 11,0; bge 5f; lwz 9,0x48(31); mr 3,31; 4:; lbzx 4,9,11; bl _s8031CAF8_0; b 6f; 5:; lwz 9,0x48(31); mr 3,31; lbz 4,0x0(9); bl _s8031CAF8_1; 6:; mr 3,31; bl _s8031CAF8_2; b 23f; 7:; lwz 0,0x14(31); mr 11,0; cmpwi 0,0; beq 8f; mr 27,11; b 9f; 8:; lwz 9,0x18(31); li 27,0; cmpwi 9,0; beq 9f; lwz 27,0x14(9); 9:; lwz 0,0x58(31); andi. 9,0,2; beq 10f; li 0,0; b 13f; 10:; cmpwi 11,0; beq 11f; mr 9,11; b 12f; 11:; lwz 11,0x18(31); li 9,0; cmpwi 11,0; beq 12f; lwz 9,0x14(11); 12:; lwz 0,0x4(9); rlwinm 0,0,6,31,31; 13:; cmpwi 0,0; beq 18f; lwz 0,0x30(31); li 29,0; cmplw 29,0; bge 23f; lis 28,-32692; 14:; lwz 11,0x68(27); rlwinm 9,29,2,0,29; mr 30,9; lwzx 0,9,11; cmpwi 0,0; beq 17f; lwz 9,0x38(31); addi 3,28,-7364; li 5,0; li 6,0; lwzx 4,30,9; bl _s8031CAF8_3; lwz 9,0x34(31); stwx 3,30,9; lwz 3,0x14(31); cmpwi 3,0; beq 15f; mr 8,3; b 16f; 15:; lwz 9,0x18(31); li 8,0; cmpwi 9,0; beq 16f; lwz 8,0x14(9); 16:; lwz 10,0xf0(8); mr 5,29; lwz 9,0x34(31); lha 3,0x40(10); lwzx 11,30,9; lwz 0,0x44(10); add 3,8,3; lwz 4,0x14(11); mtspr 8,0; blrl; 17:; addi 0,29,1; lwz 9,0x30(31); rlwinm 29,0,0,24,31; cmplw 29,9; blt 14b; b 23f; 18:; lbz 0,0x0(27); li 28,0; cmpw 28,0; bge 23f; lis 25,-32692; addi 30,31,32; li 26,0; addi 29,27,100; 19:; lwz 0,0x0(29); addi 29,29,64; cmpwi 0,0; beq 22f; lwz 4,0x8(30); addi 3,25,-7364; li 5,0; li 6,0; bl _s8031CAF8_4; addi 11,31,32; cmpwi 3,0; stw 3,0x0(30); beq 22f; lwz 3,0x14(31); cmpwi 3,0; beq 20f; mr 10,3; b 21f; 20:; lwz 9,0x18(31); li 10,0; cmpwi 9,0; beq 21f; lwz 10,0x14(9); 21:; lwz 9,0xf0(10); mr 5,28; lwzx 11,11,26; lha 3,0x38(9); lwz 0,0x3c(9); add 3,10,3; lwz 4,0x14(11); mtspr 8,0; blrl; 22:; lbz 0,0x0(27); addi 28,28,1; addi 30,30,4; addi 26,26,4; cmpw 28,0; blt 19b; 23:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s8031CAF8_0();
extern "C" void _s8031CAF8_1();
extern "C" void _s8031CAF8_2();
extern "C" void _s8031CAF8_3();
extern "C" void _s8031CAF8_4();

struct ERShader {
    void AddRefSubResources();
};

void ERShader::AddRefSubResources() {
}
