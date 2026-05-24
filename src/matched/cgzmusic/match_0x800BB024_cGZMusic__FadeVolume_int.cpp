// 0x800BB024 cGZMusic::FadeVolume(int, (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; li 29,0; stw 29,0x20(30); mr 31,5; mr 28,6; bl _s800BB024_0; cmpwi 31,0; bge 0f; stw 29,0x14(30); b 2f; 0:; cmpwi 31,1024; ble 1f; li 0,1024; stw 0,0x14(30); b 2f; 1:; stw 31,0x14(30); 2:; lis 0,17200; stw 28,0xc(1); lis 9,-32706; lfd f13,-25272(9); lis 10,-32706; stw 0,0x8(1); mr 9,11; lfs f11,-25264(10); li 3,1; lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fdivs f0,f0,f11; fmr f13,f0; fctiwz f12,f13; stfd f12,0x8(1); lwz 9,0xc(1); stw 9,0x20(30); lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s800BB024_0();

struct cGZMusic {
    void FadeVolume();
};

void cGZMusic::FadeVolume() {
}
