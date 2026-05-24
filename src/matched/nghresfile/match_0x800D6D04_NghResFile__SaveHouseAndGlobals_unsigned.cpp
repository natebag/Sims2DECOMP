// 0x800D6D04 NghResFile::SaveHouseAndGlobals(unsigned (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,5; lwz 3,-21432(13); bl _s800D6D04_0; li 0,0; lwz 4,-31920(13); sth 0,0x184(30); addi 3,30,40; li 5,0; bl _s800D6D04_1; mr 3,30; li 4,0; bl _s800D6D04_2; mr 31,3; cmpwi 31,1; bne 0f; mr 3,30; li 4,0; bl _s800D6D04_3; mr 31,3; cmpwi 31,1; bne 0f; mr 3,30; mr 4,29; li 5,0; bl _s800D6D04_4; mr 31,3; 0:; lwz 3,-21432(13); bl _s800D6D04_5; lwz 3,-26524(13); lwz 9,0x20(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s800D6D04_0();
extern "C" void _s800D6D04_1();
extern "C" void _s800D6D04_2();
extern "C" void _s800D6D04_3();
extern "C" void _s800D6D04_4();
extern "C" void _s800D6D04_5();

struct NghResFile {
    void SaveHouseAndGlobals();
};

void NghResFile::SaveHouseAndGlobals() {
}
