// 0x8036C51C ENgcAram::AsyncLoadToARAM(void (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,3; mr 25,4; mr 27,5; mr 28,6; mr 26,7; bl _s8036C51C_0; lis 9,-32690; li 29,0; addi 9,9,-6528; addi 9,9,36; lwzx 0,9,29; cmpwi 0,-1; beq 1f; 0:; addi 29,29,1; cmplwi 29,63; bgt 1f; lwzu 0,0x28(9); cmpwi 0,-1; bne 0b; 1:; cmpwi 29,64; bne 2f; bl _s8036C51C_1; mr 3,31; mr 4,25; mr 5,27; bl _s8036C51C_2; cmpwi 28,0; beq 3f; mr 3,26; mtspr 8,28; blrl; b 3f; 2:; mulli 29,29,40; lis 30,-32690; addi 30,30,-6528; addi 9,30,32; addi 11,30,36; mr 3,31; mr 4,27; stwx 28,9,29; stwx 26,11,29; bl _s8036C51C_3; lis 10,-32713; mr 7,31; mr 8,25; mr 9,27; li 6,1; add 3,29,30; addi 10,10,-14828; li 4,0; li 5,0; bl _s8036C51C_4; bl _s8036C51C_5; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s8036C51C_0();
extern "C" void _s8036C51C_1();
extern "C" void _s8036C51C_2();
extern "C" void _s8036C51C_3();
extern "C" void _s8036C51C_4();
extern "C" void _s8036C51C_5();

struct ENgcAram {
    void AsyncLoadToARAM();
};

void ENgcAram::AsyncLoadToARAM() {
}
