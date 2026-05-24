// 0x8004032C EGlobal::GetNghFamilyName(BString2 (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 27,0x4c(1); stw 0,0x64(1); mr 27,4; mr 3,27; bl _s8004032C_0; cmpwi 3,0; beq 2f; mr 3,27; li 4,0; bl _s8004032C_1; lhz 0,0x0(3); cmpwi 0,35; bne 2f; mr 3,27; li 29,0; bl _s8004032C_2; mr 30,3; mr 3,27; addi 31,30,2; bl _s8004032C_3; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s8004032C_4; lhz 0,0x2(30); mr 28,3; sth 0,0x0(28); lbz 9,0x1(31); extsb 0,9; stb 9,0x8(1); cmpwi 0,0; beq 1f; addi 10,1,8; mr 11,28; 0:; addi 29,29,1; addi 31,31,2; cmpwi 29,63; bgt 1f; lhz 0,0x0(31); sthu 0,0x2(11); lbz 9,0x1(31); extsb 0,9; stbx 9,10,29; cmpwi 0,0; bne 0b; 1:; mr 3,27; mr 4,28; bl _s8004032C_5; cmpwi 28,0; beq 2f; mr 3,28; bl _s8004032C_6; 2:; lwz 0,0x64(1); mtspr 8,0; lmw 27,0x4c(1); addi 1,1,96"

extern "C" void _s8004032C_0();
extern "C" void _s8004032C_1();
extern "C" void _s8004032C_2();
extern "C" void _s8004032C_3();
extern "C" void _s8004032C_4();
extern "C" void _s8004032C_5();
extern "C" void _s8004032C_6();

struct EGlobal {
    void GetNghFamilyName_BString2();
};

void EGlobal::GetNghFamilyName_BString2() {
}
