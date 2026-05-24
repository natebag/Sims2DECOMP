// 0x8008554C WrapperPaneBase::CalculateMenuWidthPixels(void) (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f31,0x30(1); stmw 29,0x24(1); stw 0,0x3c(1); addi 11,3,8; lwz 31,0x8(3); lwz 0,0x4(11); lis 9,-32707; lfs f31,0x72a0(9); cmpw 31,0; beq 2f; mr 29,11; addi 30,1,8; 0:; lwz 11,0x0(31); lwz 0,0x0(11); cmpwi 0,1; bne 1f; lwz 9,0x1c(11); lha 3,0x70(9); lwz 0,0x74(9); add 3,11,3; mtspr 8,0; blrl; lfs f0,0x0(3); stfs f0,0x8(1); lfs f13,0x4(3); stfs f13,0x4(30); lfs f0,0x8(1); fcmpu 0,f0,f31; ble 1f; fmr f31,f0; 1:; lwz 0,0x4(29); addi 31,31,4; cmpw 31,0; bne 0b; 2:; lwz 10,-26392(13); lis 8,17200; lis 11,-32707; lwz 0,0x18(10); mr 3,9; lfd f13,0x72a8(11); xoris 0,0,32768; stw 0,0x1c(1); stw 8,0x18(1); lfd f0,0x18(1); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f31,f0; fmr f13,f0; fctiwz f12,f13; stfd f12,0x18(1); lwz 3,0x1c(1); lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x24(1); lfd f31,0x30(1); addi 1,1,56"

struct WrapperPaneBase {
    void CalculateMenuWidthPixels();
};

void WrapperPaneBase::CalculateMenuWidthPixels() {
}
