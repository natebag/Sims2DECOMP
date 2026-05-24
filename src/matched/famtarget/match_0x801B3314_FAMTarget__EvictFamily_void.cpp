// 0x801B3314 FAMTarget::EvictFamily(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 4,0x14c(31); bl _s801B3314_0; lwz 0,-31536(13); mr 30,3; cmpwi 0,0; bne 0f; li 3,120; bl _s801B3314_1; bl _s801B3314_2; stw 3,-31536(13); 0:; lwz 3,-31536(13); lis 4,16356; ori 4,4,22315; bl _s801B3314_3; addi 3,30,-1; bl _s801B3314_4; mr 3,31; li 4,2; bl _s801B3314_5; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s801B3314_0();
extern "C" void _s801B3314_1();
extern "C" void _s801B3314_2();
extern "C" void _s801B3314_3();
extern "C" void _s801B3314_4();
extern "C" void _s801B3314_5();

struct FAMTarget {
    void EvictFamily();
};

void FAMTarget::EvictFamily() {
}
