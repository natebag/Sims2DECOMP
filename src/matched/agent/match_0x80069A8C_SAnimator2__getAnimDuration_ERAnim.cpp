// 0x80069A8C SAnimator2::getAnimDuration(ERAnim (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32707; mr. 4,4; lfs f1,0x4c5c(9); beq 0f; lwz 9,0x18(4); lis 0,17200; lis 11,-32707; addi 9,9,-1; lfd f13,0x4c60(11); xoris 9,9,32768; lfs f12,0x64(4); stw 9,0xc(1); stw 0,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f1,f0; fdivs f1,f1,f12; 0:; addi 1,1,16"
extern "C" void f_80069A8C() {}
