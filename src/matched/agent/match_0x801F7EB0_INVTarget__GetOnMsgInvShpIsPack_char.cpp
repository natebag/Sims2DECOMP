// 0x801F7EB0 INVTarget::GetOnMsgInvShpIsPack(char (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,0x84(3); addi 11,13,-28700; addi 3,3,216; mr 31,4; rlwinm 9,9,2,0,29; lwzx 0,9,11; rlwinm 0,0,2,0,29; lwzx 3,3,0; bl _s801F7EB0_0; cmpwi 3,0; li 5,0; beq 0f; li 5,1; 0:; lis 4,-32704; mr 3,31; addi 4,4,-30836; crxor 6,6,6; bl _s801F7EB0_1; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801F7EB0_0();
extern "C" void _s801F7EB0_1();
extern "C" void f_801F7EB0() {}
