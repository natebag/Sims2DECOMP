// 0x800D77B0 NghResFile::ReadFromCache(void) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,-21432(13); bl _s800D77B0_0; mr 3,31; li 4,0; bl _s800D77B0_1; mr 3,31; li 4,0; li 5,0; bl _s800D77B0_2; cmpwi 3,1; li 3,-1; bne 0f; mr 3,31; li 4,1; bl _s800D77B0_3; mr 3,31; li 4,0; li 5,0; bl _s800D77B0_4; cmpwi 3,1; li 3,-1; bne 0f; mr 3,31; li 4,2; bl _s800D77B0_5; mr 3,31; li 4,0; li 5,0; bl _s800D77B0_6; cmpwi 3,1; li 3,-1; bne 0f; mr 3,31; bl _s800D77B0_7; lwz 3,-21432(13); bl _s800D77B0_8; li 3,0; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s800D77B0_0();
extern "C" void _s800D77B0_1();
extern "C" void _s800D77B0_2();
extern "C" void _s800D77B0_3();
extern "C" void _s800D77B0_4();
extern "C" void _s800D77B0_5();
extern "C" void _s800D77B0_6();
extern "C" void _s800D77B0_7();
extern "C" void _s800D77B0_8();

struct NghResFile {
    void ReadFromCache();
};

void NghResFile::ReadFromCache() {
}
