// 0x802EDBF0 EAnimController::SetAllTrackIntensities(float) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 29,0xc(1); stw 0,0x24(1); mr 31,3; li 30,0; lwz 0,0x40(31); fmr f31,f1; cmpw 30,0; bge 2f; li 29,0; 0:; lwz 0,0x44(31); add 4,29,0; lwz 9,0xa8(4); cmpwi 9,1; bne 1f; mr 3,31; fmr f1,f31; li 5,1; bl _s802EDBF0_0; 1:; lwz 0,0x40(31); addi 30,30,1; addi 29,29,176; cmpw 30,0; blt 0b; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0xc(1); lfd f31,0x18(1); addi 1,1,32"

extern "C" void _s802EDBF0_0();

struct EAnimController {
    void SetAllTrackIntensities();
};

void EAnimController::SetAllTrackIntensities() {
}
