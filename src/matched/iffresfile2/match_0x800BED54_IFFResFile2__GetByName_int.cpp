// 0x800BED54 IFFResFile2::GetByName(int, (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 26,0x50(1); stw 0,0x6c(1); mr 31,3; mr 26,4; lwz 9,0xc(31); mr 28,5; mr 27,6; lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,31; li 4,-49; bl _s800BED54_0; b 1f; 0:; mr 3,31; li 4,0; bl _s800BED54_1; 1:; mr 3,31; bl _s800BED54_2; cmpwi 3,0; li 3,0; bne 4f; mr 3,28; bl _s800BED54_3; cmpwi 3,0; beq 2f; addi 30,1,8; lwz 29,0x138(31); addi 4,30,8; li 5,64; mr 3,30; bl _s800BED54_4; mr 3,30; mr 4,28; li 5,-1; bl _s800BED54_5; mr 5,30; mr 3,29; mr 4,26; mr 6,27; bl _s800BED54_6; mr. 30,3; bne 3f; 2:; mr 3,31; li 4,-99; bl _s800BED54_7; li 3,0; b 4f; 3:; mr 5,27; mr 6,26; mr 4,30; mr 3,31; bl _s800BED54_8; mr 4,3; mr 3,31; bl _s800BED54_9; lwz 3,0xc(30); 4:; lwz 0,0x6c(1); mtspr 8,0; lmw 26,0x50(1); addi 1,1,104"

extern "C" void _s800BED54_0();
extern "C" void _s800BED54_1();
extern "C" void _s800BED54_2();
extern "C" void _s800BED54_3();
extern "C" void _s800BED54_4();
extern "C" void _s800BED54_5();
extern "C" void _s800BED54_6();
extern "C" void _s800BED54_7();
extern "C" void _s800BED54_8();
extern "C" void _s800BED54_9();

struct IFFResFile2 {
    void GetByName();
};

void IFFResFile2::GetByName() {
}
