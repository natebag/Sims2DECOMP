// 0x80141208 cSimulatorImpl::Pause(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x0(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; li 3,189; li 4,0; bl _s80141208_0; 0:; lhz 0,0x36(31); lis 9,-32706; lfs f0,-10652(9); ori 0,0,1; stfs f0,0xa8(31); sth 0,0x36(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80141208_0();

struct cSimulatorImpl {
    void Pause();
};

void cSimulatorImpl::Pause() {
}
