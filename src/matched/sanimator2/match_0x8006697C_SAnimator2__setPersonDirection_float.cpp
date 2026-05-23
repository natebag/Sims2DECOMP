// 0x8006697C SAnimator2::setPersonDirection(float) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); lis 9,-32707; lis 11,-32707; lfs f13,0x4af8(9); fneg f1,f1; lfs f0,0x4afc(11); mr 31,3; fadds f1,f1,f13; fdivs f1,f1,f0; bl _s8006697C_0; fctiwz f0,f1; stfd f0,0x10(1); lwz 5,0x14(1); addic. 5,5,2; bge 1f; 0:; addic. 5,5,8; blt 0b; 1:; mr 0,5; cmpwi 5,0; bge 2f; addi 0,5,7; 2:; lwz 9,0x4(31); rlwinm 0,0,0,0,28; subf 5,0,5; li 4,1; lwz 11,0x0(9); extsh 5,5; lwz 9,0x4(11); lha 3,0x1e8(9); lwz 0,0x1ec(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"

extern "C" void _s8006697C_0();

struct SAnimator2 {
    void setPersonDirection();
};

void SAnimator2::setPersonDirection() {
}
