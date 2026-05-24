// 0x800BC0E0 HouseImpl::EnterLiveMode(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 3,-21472(13); bl _s800BC0E0_0; lwz 3,-21472(13); bl _s800BC0E0_1; lwz 3,-21472(13); bl _s800BC0E0_2; lwz 11,-21484(13); lwz 9,0x0(11); lwz 0,0x184(9); lha 3,0x180(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(30); lha 3,0x88(9); lwz 0,0x8c(9); add 3,30,3; mtspr 8,0; blrl; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800BC0E0_0();
extern "C" void _s800BC0E0_1();
extern "C" void _s800BC0E0_2();

struct HouseImpl {
    void EnterLiveMode();
};

void HouseImpl::EnterLiveMode() {
}
