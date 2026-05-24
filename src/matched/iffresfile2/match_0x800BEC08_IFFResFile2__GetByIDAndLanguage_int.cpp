// 0x800BEC08 IFFResFile2::GetByIDAndLanguage(int, (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 28,4; lwz 9,0xc(31); mr 30,5; mr 27,6; mr 29,7; lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,31; li 4,-49; bl _s800BEC08_0; b 1f; 0:; mr 3,31; li 4,0; bl _s800BEC08_1; 1:; mr 3,31; bl _s800BEC08_2; cmpwi 3,0; li 3,0; bne 5f; lwz 3,0x138(31); mr 5,30; mr 6,27; mr 4,28; mr 7,29; bl _s800BEC08_3; mr. 30,3; bne 4f; lwz 9,0xc(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 2f; mr 3,31; li 4,-49; bl _s800BEC08_4; b 3f; 2:; mr 3,31; li 4,-98; bl _s800BEC08_5; 3:; li 3,0; b 5f; 4:; mr 5,29; mr 6,28; mr 4,30; mr 3,31; bl _s800BEC08_6; mr 4,3; mr 3,31; bl _s800BEC08_7; lwz 3,0xc(30); 5:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s800BEC08_0();
extern "C" void _s800BEC08_1();
extern "C" void _s800BEC08_2();
extern "C" void _s800BEC08_3();
extern "C" void _s800BEC08_4();
extern "C" void _s800BEC08_5();
extern "C" void _s800BEC08_6();
extern "C" void _s800BEC08_7();

struct IFFResFile2 {
    void GetByIDAndLanguage();
};

void IFFResFile2::GetByIDAndLanguage() {
}
