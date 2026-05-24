// 0x802EE06C EAnimController::BlendAllOutgoingTracks(float, (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; mfcr 12; stfd f29,0x20(1); stfd f30,0x28(1); stfd f31,0x30(1); stmw 28,0x10(1); stw 0,0x3c(1); stw 12,0xc(1); mr 31,3; fmr f30,f1; lwz 0,0x38(31); fmr f31,f2; li 30,0; addic. 9,0,-1; blt 4f; lis 9,-32702; cmpwi 4,4,0; lfs f29,-4420(9); lis 28,-32702; li 29,0; 0:; lwz 0,0x44(31); add 4,29,0; lwz 9,0xa8(4); cmpwi 9,1; bne 3f; lwz 0,0x30(4); andis. 9,0,4; beq 3f; lfs f0,0x50(4); fcmpu 0,f0,f29; ble 3f; beq cr4,2f; lbz 0,0xa0(4); cmpwi 0,0; beq 1f; cmpwi 0,4; bne 3f; 1:; lfs f3,-4416(28); mr 3,31; fmr f1,f30; fmr f2,f31; bl _s802EE06C_0; b 3f; 2:; lbz 0,0xa0(4); cmpwi 0,0; bne 3f; lfs f3,-4416(28); mr 3,31; fmr f1,f30; fmr f2,f31; bl _s802EE06C_1; 3:; lwz 9,0x38(31); addi 30,30,1; addi 29,29,176; addi 9,9,-1; cmpw 30,9; ble 0b; 4:; lwz 0,0x3c(1); lwz 12,0xc(1); mtspr 8,0; lmw 28,0x10(1); lfd f29,0x20(1); lfd f30,0x28(1); lfd f31,0x30(1); mtcrf 8,12; addi 1,1,56"

extern "C" void _s802EE06C_0();
extern "C" void _s802EE06C_1();

struct EAnimController {
    void BlendAllOutgoingTracks();
};

void EAnimController::BlendAllOutgoingTracks() {
}
