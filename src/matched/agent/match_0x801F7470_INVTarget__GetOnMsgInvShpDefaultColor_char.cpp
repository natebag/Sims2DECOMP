// 0x801F7470 INVTarget::GetOnMsgInvShpDefaultColor(char (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 3,4; li 5,0; lis 4,-32704; addi 4,4,-30836; crxor 6,6,6; bl _s801F7470_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801F7470_0();
extern "C" void f_801F7470() {}
