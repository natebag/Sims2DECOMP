// 0x80160E38 CasGenetics::LoadGrandparentList(bool) (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 29,3; lwz 9,0x0(29); lwz 0,0x4(29); subf 0,9,0; rlwinm. 9,0,30,2,31; beq 0f; cmpwi 4,0; li 3,1; beq 5f; mr 3,29; bl _s80160E38_0; 0:; lis 3,-32693; lis 4,10675; addi 3,3,17784; ori 4,4,11510; li 5,0; li 6,0; bl _s80160E38_1; mr. 30,3; bne 1f; mr 3,29; bl _s80160E38_2; b 4f; 1:; bl _s80160E38_3; li 4,12; li 5,0; bl _s80160E38_4; lwz 0,0x18(30); mr 31,3; li 9,0; li 11,1; stw 0,0x0(31); lis 5,17223; stw 9,0x8(31); mr 3,29; mr 4,31; ori 5,5,18256; lwz 0,0x14(30); addi 6,1,8; stw 0,0x4(31); stw 11,0x8(1); bl _s80160E38_5; cmpwi 31,0; beq 3f; lwz 0,0x8(31); cmpwi 0,0; beq 2f; bl _s80160E38_6; lwz 4,0x4(31); bl _s80160E38_7; 2:; bl _s80160E38_8; mr 4,31; bl _s80160E38_9; 3:; cmpwi 30,0; beq 4f; mr 3,30; bl _s80160E38_10; 4:; li 3,1; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s80160E38_0();
extern "C" void _s80160E38_1();
extern "C" void _s80160E38_2();
extern "C" void _s80160E38_3();
extern "C" void _s80160E38_4();
extern "C" void _s80160E38_5();
extern "C" void _s80160E38_6();
extern "C" void _s80160E38_7();
extern "C" void _s80160E38_8();
extern "C" void _s80160E38_9();
extern "C" void _s80160E38_10();

struct CasGenetics {
    void LoadGrandparentList();
};

void CasGenetics::LoadGrandparentList() {
}
