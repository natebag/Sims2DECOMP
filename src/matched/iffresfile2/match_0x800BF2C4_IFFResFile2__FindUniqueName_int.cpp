// 0x800BF2C4 IFFResFile2::FindUniqueName(int, (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-184(1); mfspr 0,8; stmw 25,0x9c(1); stw 0,0xbc(1); mr 29,3; mr 25,4; lwz 9,0xc(29); mr 31,5; lha 3,0x60(9); lwz 0,0x64(9); add 3,29,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,29; li 4,-49; bl _s800BF2C4_0; b 1f; 0:; mr 3,29; li 4,0; bl _s800BF2C4_1; 1:; mr 3,29; bl _s800BF2C4_2; cmpwi 3,0; bne 4f; addi 30,1,8; li 5,64; addi 4,30,8; mr 3,30; bl _s800BF2C4_3; li 27,0; mr 3,30; mr 4,31; bl _s800BF2C4_4; addi 26,1,80; 2:; addi 4,1,88; addi 3,1,80; lwz 30,0x138(29); li 5,64; bl _s800BF2C4_5; li 28,1; addi 3,1,80; mr 4,31; li 5,-1; bl _s800BF2C4_6; mr 3,30; mr 4,25; mr 5,26; li 6,0; bl _s800BF2C4_7; cmpwi 3,0; beq 3f; addi 4,1,8; mr 3,31; bl _s800BF2C4_8; li 28,0; mr 4,27; mr 3,31; bl _s800BF2C4_9; addi 27,27,1; 3:; cmpwi 28,0; beq 2b; 4:; lwz 0,0xbc(1); mtspr 8,0; lmw 25,0x9c(1); addi 1,1,184"

extern "C" void _s800BF2C4_0();
extern "C" void _s800BF2C4_1();
extern "C" void _s800BF2C4_2();
extern "C" void _s800BF2C4_3();
extern "C" void _s800BF2C4_4();
extern "C" void _s800BF2C4_5();
extern "C" void _s800BF2C4_6();
extern "C" void _s800BF2C4_7();
extern "C" void _s800BF2C4_8();
extern "C" void _s800BF2C4_9();

struct IFFResFile2 {
    void FindUniqueName();
};

void IFFResFile2::FindUniqueName() {
}
