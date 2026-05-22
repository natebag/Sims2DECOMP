// 0x801F74A4 INVTarget::GetOnMsgInvShpCategoryCount(char (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; lis 11,-32704; lwz 0,0x178(9); mr 3,4; lwz 5,0x17c(9); addi 4,11,-30836; subf 5,0,5; srawi 5,5,3; crxor 6,6,6; bl _s801F74A4_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801F74A4_0();
extern "C" void f_801F74A4() {}
