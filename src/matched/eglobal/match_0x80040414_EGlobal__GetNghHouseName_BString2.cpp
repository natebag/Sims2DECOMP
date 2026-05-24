// 0x80040414 EGlobal::GetNghHouseName(BString2 (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 26,0x48(1); stw 0,0x64(1); mr 27,4; mr 31,3; mr 3,27; bl _s80040414_0; cmpwi 3,0; beq 5f; mr 3,27; li 4,0; bl _s80040414_1; lhz 0,0x0(3); cmpwi 0,35; bne 5f; lwz 3,0xe8(31); lis 4,-32707; addi 4,4,10132; li 29,0; bl _s80040414_2; mr 26,3; mr 3,27; bl _s80040414_3; mr 30,3; mr 3,27; addi 31,30,2; bl _s80040414_4; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s80040414_5; lhz 0,0x2(30); mr 28,3; addi 5,1,8; sth 0,0x0(28); lbz 9,0x1(31); extsb 0,9; stb 9,0x8(1); cmpwi 0,0; beq 1f; mr 10,5; mr 11,28; 0:; addi 29,29,1; addi 31,31,2; cmpwi 29,63; bgt 1f; lhz 0,0x0(31); sthu 0,0x2(11); lbz 9,0x1(31); extsb 0,9; stbx 9,10,29; cmpwi 0,0; bne 0b; 1:; lis 9,-32697; mr 4,26; lwz 3,0x5eb4(9); bl _s80040414_6; mr. 3,3; beq 3f; lwz 3,0x0(3); li 4,0; cmpwi 3,0; beq 2f; lwz 4,0x0(3); 2:; mr 3,27; bl _s80040414_7; b 4f; 3:; mr 3,27; mr 4,28; bl _s80040414_8; 4:; cmpwi 28,0; beq 5f; mr 3,28; bl _s80040414_9; 5:; lwz 0,0x64(1); mtspr 8,0; lmw 26,0x48(1); addi 1,1,96"

extern "C" void _s80040414_0();
extern "C" void _s80040414_1();
extern "C" void _s80040414_2();
extern "C" void _s80040414_3();
extern "C" void _s80040414_4();
extern "C" void _s80040414_5();
extern "C" void _s80040414_6();
extern "C" void _s80040414_7();
extern "C" void _s80040414_8();
extern "C" void _s80040414_9();

struct EGlobal {
    void GetNghHouseName_BString2();
};

void EGlobal::GetNghHouseName_BString2() {
}
