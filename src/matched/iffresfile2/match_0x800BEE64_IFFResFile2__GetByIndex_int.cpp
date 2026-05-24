// 0x800BEE64 IFFResFile2::GetByIndex(int, (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,4; lwz 9,0xc(31); mr 30,5; mr 29,6; lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,31; li 4,-49; bl _s800BEE64_0; b 1f; 0:; mr 3,31; li 4,0; bl _s800BEE64_1; 1:; mr 3,31; bl _s800BEE64_2; cmpwi 3,0; li 3,0; bne 5f; lwz 3,0x138(31); mr 5,30; mr 4,28; mr 6,29; bl _s800BEE64_3; mr. 30,3; bne 4f; lwz 9,0xc(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 2f; mr 3,31; li 4,-49; bl _s800BEE64_4; b 3f; 2:; mr 3,31; li 4,-98; bl _s800BEE64_5; 3:; li 3,0; b 5f; 4:; mr 5,29; mr 6,28; mr 4,30; mr 3,31; bl _s800BEE64_6; mr 4,3; mr 3,31; bl _s800BEE64_7; lwz 3,0xc(30); 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s800BEE64_0();
extern "C" void _s800BEE64_1();
extern "C" void _s800BEE64_2();
extern "C" void _s800BEE64_3();
extern "C" void _s800BEE64_4();
extern "C" void _s800BEE64_5();
extern "C" void _s800BEE64_6();
extern "C" void _s800BEE64_7();

struct IFFResFile2 {
    void GetByIndex();
};

void IFFResFile2::GetByIndex() {
}
