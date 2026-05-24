// 0x802842C0 AptAnimationPoolData::addAnalogInput(AptAnalogStickInfo) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,4; lwz 0,0xc(9); cmpwi 0,501; bne 0f; lfs f0,0x0(9); stfs f0,0x74(3); lfs f13,0x4(9); stfs f13,0x78(3); lbz 0,0x8(9); stb 0,0x7c(3); b 1f; 0:; cmpwi 0,502; bne 1f; lfs f0,0x0(9); stfs f0,0x84(3); lfs f13,0x4(9); stfs f13,0x88(3); lbz 0,0x8(9); stb 0,0x8c(3); 1:; lbz 4,0x8(9); lwz 0,0xc(9); rlwinm 4,4,2,0,29; rlwinm 0,0,17,0,14; ori 4,4,1; or 4,0,4; bl _s802842C0_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s802842C0_0();

struct AptAnimationPoolData {
    void addAnalogInput_AptAnalogStickInfo();
};

void AptAnimationPoolData::addAnalogInput_AptAnalogStickInfo() {
}
