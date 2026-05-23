// 0x80069230 SAnimator2::getPersonDirection(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lwz 11,0x4(3); li 4,1; lwz 10,0x0(11); lwz 9,0x4(10); lwz 0,0x264(9); lha 3,0x260(9); mtspr 8,0; add 3,10,3; blrl; xoris 3,3,32768; stw 3,0xc(1); lis 0,17200; lis 11,-32707; lis 10,-32707; stw 0,0x8(1); lis 8,-32707; lfd f13,0x4bf0(11); lis 7,-32707; lfd f0,0x8(1); lfs f11,0x4bf8(10); fsub f0,f0,f13; lfs f12,0x4bfc(8); frsp f0,f0; lfs f13,0x4c00(7); fsubs f1,f0,f11; fmuls f1,f1,f12; fcmpu 0,f1,f13; bge 0f; lis 9,-32707; lfs f0,0x4c04(9); fadds f1,f1,f0; 0:; lis 9,-32707; lfs f0,0x4c08(9); fcmpu 0,f1,f0; ble 1f; lis 9,-32707; lfs f0,0x4c04(9); fsubs f1,f1,f0; 1:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"

struct SAnimator2 {
    void getPersonDirection();
};

void SAnimator2::getPersonDirection() {
}
