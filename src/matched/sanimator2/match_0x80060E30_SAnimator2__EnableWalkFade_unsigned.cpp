// 0x80060E30 SAnimator2::EnableWalkFade(unsigned (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="lwz 11,0xc(3); lwz 10,0x14(3); lwz 0,0x0(11); lwz 9,0x4(11); subf 9,0,9; srawi 9,9,3; addi 9,9,-2; cmpw 10,9; bge 1f; 0:; lwz 0,0x0(4); rlwinm 0,0,0,29,27; stw 0,0x0(4); blr; 1:; ble 3f; 2:; lbz 0,0x5f8(3); cmpwi 0,1; beqlr; lwz 0,0x0(4); ori 0,0,8; stw 0,0x0(4); blr; 3:; fneg f13,f2; lis 11,-32707; fdivs f13,f13,f3; lfs f11,0x47d4(11); lis 9,-32707; lfs f10,0x47d8(9); fmuls f0,f3,f3; fmuls f12,f2,f3; fmuls f0,f0,f13; fmadds f0,f0,f11,f12; fdivs f0,f1,f0; fcmpu 0,f0,f10; blt 2b; b 0b"

struct SAnimator2 {
    void EnableWalkFade();
};

void SAnimator2::EnableWalkFade() {
}
