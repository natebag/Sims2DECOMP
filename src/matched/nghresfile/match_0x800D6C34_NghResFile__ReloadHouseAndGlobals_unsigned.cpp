// 0x800D6C34 NghResFile::ReloadHouseAndGlobals(unsigned (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,5; lwz 3,-21432(13); bl _s800D6C34_0; mr 3,30; li 4,0; bl _s800D6C34_1; mr 3,30; li 4,0; li 5,0; bl _s800D6C34_2; mr 31,3; cmpwi 31,1; bne 0f; mr 3,30; li 4,1; bl _s800D6C34_3; mr 3,30; li 4,0; li 5,0; bl _s800D6C34_4; mr 31,3; cmpwi 31,1; bne 0f; mr 3,30; mr 4,29; bl _s800D6C34_5; mr 3,30; mr 4,29; li 5,0; li 6,0; bl _s800D6C34_6; mr 31,3; 0:; lwz 3,-21432(13); bl _s800D6C34_7; lwz 3,-26524(13); lwz 9,0x20(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s800D6C34_0();
extern "C" void _s800D6C34_1();
extern "C" void _s800D6C34_2();
extern "C" void _s800D6C34_3();
extern "C" void _s800D6C34_4();
extern "C" void _s800D6C34_5();
extern "C" void _s800D6C34_6();
extern "C" void _s800D6C34_7();

struct NghResFile {
    void ReloadHouseAndGlobals();
};

void NghResFile::ReloadHouseAndGlobals() {
}
