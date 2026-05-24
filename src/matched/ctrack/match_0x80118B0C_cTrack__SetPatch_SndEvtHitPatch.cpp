// 0x80118B0C cTrack::SetPatch(SndEvtHitPatch (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 0,0xc(31); fmr f31,f1; cmpwi 0,0; beq 1f; bl _s80118B0C_0; lwz 3,0xc(31); cmpwi 3,0; beq 0f; li 4,3; bl _s80118B0C_1; 0:; li 0,0; stw 0,0xc(31); 1:; lwz 3,0x50(31); cmpwi 3,0; beq 3f; bl _s80118B0C_2; lwz 3,0x50(31); cmpwi 3,0; beq 2f; li 4,3; bl _s80118B0C_3; 2:; li 0,0; stw 0,0x50(31); 3:; cmpwi 30,0; beq 5f; li 3,28; bl _s80118B0C_4; mr 4,30; fmr f1,f31; bl _s80118B0C_5; stw 3,0xc(31); cmpwi 3,0; bne 4f; li 3,0; b 6f; 4:; lwz 9,0x0(31); lbz 4,0x1b(9); bl _s80118B0C_6; lwz 3,0xc(31); bl _s80118B0C_7; stw 3,0x50(31); mr 3,31; bl _s80118B0C_8; 5:; li 3,1; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"

extern "C" void _s80118B0C_0();
extern "C" void _s80118B0C_1();
extern "C" void _s80118B0C_2();
extern "C" void _s80118B0C_3();
extern "C" void _s80118B0C_4();
extern "C" void _s80118B0C_5();
extern "C" void _s80118B0C_6();
extern "C" void _s80118B0C_7();
extern "C" void _s80118B0C_8();

struct cTrack {
    void SetPatch_SndEvtHitPatch();
};

void cTrack::SetPatch_SndEvtHitPatch() {
}
