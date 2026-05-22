// 0x80066940 SAnimator2::stopCurAnim(bool) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,0; beq 0f; lis 9,-32707; li 0,0; lfs f0,0x4af4(9); stw 0,0xc8(3); stfs f0,0xd0(3); 0:; lwz 0,0x61c(3); li 9,0; lwz 11,0xdc(3); rlwinm 0,0,0,24,22; stw 9,0xd4(3); stw 11,0xe0(3); stw 0,0x61c(3)"
extern "C" void f_80066940() {}
