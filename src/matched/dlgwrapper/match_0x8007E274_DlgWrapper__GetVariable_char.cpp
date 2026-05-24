// 0x8007E274 DlgWrapper::GetVariable(char (460 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; mr 31,4; lwz 3,0xac(28); bl _s8007E274_0; mr. 29,3; bne 8f; lis 30,-32707; mr 3,31; addi 30,30,27140; bl _s8007E274_1; mr 29,3; mr 3,30; bl _s8007E274_2; add 29,29,3; addi 3,29,1; bl _s8007E274_3; mr 29,3; mr 4,31; bl _s8007E274_4; mr 4,30; mr 3,29; bl _s8007E274_5; lis 4,-32707; mr 3,31; addi 4,4,27160; bl _s8007E274_6; mr. 3,3; beq 5f; lis 4,-32707; mr 3,31; addi 4,4,27176; bl _s8007E274_7; cmpwi 3,0; bne 0f; lfs f1,0xc4(28); b 3f; 0:; lis 4,-32707; mr 3,31; addi 4,4,27200; bl _s8007E274_8; cmpwi 3,0; bne 1f; lfs f1,0xc8(28); b 3f; 1:; lis 4,-32707; mr 3,31; addi 4,4,27220; bl _s8007E274_9; cmpwi 3,0; bne 2f; lfs f1,0xbc(28); b 3f; 2:; lis 4,-32707; mr 3,31; addi 4,4,27232; bl _s8007E274_10; cmpwi 3,0; bne 4f; lfs f1,0xc0(28); 3:; lis 4,-32707; addi 4,4,27196; mr 3,29; creqv 6,6,6; bl _s8007E274_11; b 8f; 4:; lis 4,-32707; mr 3,31; addi 4,4,27244; bl _s8007E274_12; mr. 3,3; beq 5f; lis 4,-32707; mr 3,31; addi 4,4,27264; bl _s8007E274_13; mr. 3,3; bne 6f; 5:; li 0,48; stb 3,0x1(29); stb 0,0x0(29); b 8f; 6:; lis 4,-32707; mr 3,31; addi 4,4,27284; bl _s8007E274_14; cmpwi 3,0; beq 7f; mr 3,29; bl _s8007E274_15; li 3,0; b 9f; 7:; lwz 9,0xac(28); lwz 10,0x60(9); lwz 11,0x1c(10); lha 3,0x70(11); lwz 0,0x74(11); add 3,10,3; mtspr 8,0; blrl; lfs f1,0x0(3); lis 4,-32707; addi 4,4,27196; mr 3,29; creqv 6,6,6; bl _s8007E274_16; 8:; mr 3,29; 9:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s8007E274_0();
extern "C" void _s8007E274_1();
extern "C" void _s8007E274_2();
extern "C" void _s8007E274_3();
extern "C" void _s8007E274_4();
extern "C" void _s8007E274_5();
extern "C" void _s8007E274_6();
extern "C" void _s8007E274_7();
extern "C" void _s8007E274_8();
extern "C" void _s8007E274_9();
extern "C" void _s8007E274_10();
extern "C" void _s8007E274_11();
extern "C" void _s8007E274_12();
extern "C" void _s8007E274_13();
extern "C" void _s8007E274_14();
extern "C" void _s8007E274_15();
extern "C" void _s8007E274_16();

struct DlgWrapper {
    void GetVariable();
};

void DlgWrapper::GetVariable() {
}
