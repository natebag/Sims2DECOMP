// 0x801AE514 E2ETarget::OnSaveDialogDoneCB(int) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 4,4,-1; cmplwi 4,1; bgt 0f; lfs f12,0xc8(3); lfs f11,0xd4(3); lfs f0,0xcc(3); fmr f1,f12; lfs f13,0xd0(3); stfs f0,-30440(13); stfs f13,-30436(13); stfs f11,-30432(13); stfs f12,-30444(13); bl _s801AE514_0; lfs f1,-30436(13); bl _s801AE514_1; lfs f1,-30432(13); bl _s801AE514_2; lfs f1,-30440(13); bl _s801AE514_3; 0:; lis 3,-32705; li 4,0; addi 3,3,-1368; li 5,0; li 6,0; li 7,0; bl _s801AE514_4; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s801AE514_0();
extern "C" void _s801AE514_1();
extern "C" void _s801AE514_2();
extern "C" void _s801AE514_3();
extern "C" void _s801AE514_4();

struct E2ETarget {
    void OnSaveDialogDoneCB();
};

void E2ETarget::OnSaveDialogDoneCB() {
}
