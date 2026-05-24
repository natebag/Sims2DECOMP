// 0x800BB760 HouseImpl::RefreshHouse(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-21472(13); bl _s800BB760_0; lwz 11,-21488(13); li 4,0; lwz 9,0x0(11); lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,11,3; blrl; lwz 3,-21472(13); bl _s800BB760_1; lis 3,-32697; addi 3,3,24012; bl _s800BB760_2; lwz 11,-21424(13); lwz 9,0x0(11); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s800BB760_0();
extern "C" void _s800BB760_1();
extern "C" void _s800BB760_2();

struct HouseImpl {
    void RefreshHouse();
};

void HouseImpl::RefreshHouse() {
}
