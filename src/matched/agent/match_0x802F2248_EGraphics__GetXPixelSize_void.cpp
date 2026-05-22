// 0x802F2248 EGraphics::GetXPixelSize(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lwz 0,0x18(3); lis 10,17200; lis 9,-32702; xori 0,0,32768; lfd f0,-3936(9); stw 0,0xc(1); lis 9,-32702; lfs f13,-3928(9); stw 10,0x8(1); lfd f1,0x8(1); fsub f1,f1,f0; frsp f1,f1; fdivs f1,f13,f1; addi 1,1,16"
extern "C" void f_802F2248() {}
