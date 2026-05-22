// 0x801F7F1C INVTarget::GetOnMsgInvHelpMode(char (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 9,0x84(3); addi 11,13,-28700; addi 3,3,216; mr 30,4; rlwinm 9,9,2,0,29; li 29,1; lwzx 0,9,11; rlwinm 0,0,2,0,29; lwzx 31,3,0; cmpwi 31,0; beq 0f; mr 3,31; bl _s801F7F1C_0; cmpwi 3,2; bne 0f; mr 3,31; bl _s801F7F1C_1; cmpwi 3,1; bne 0f; li 29,0; 0:; lis 4,-32704; mr 3,30; addi 4,4,-30836; mr 5,29; crxor 6,6,6; bl _s801F7F1C_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801F7F1C_0();
extern "C" void _s801F7F1C_1();
extern "C" void _s801F7F1C_2();
extern "C" void f_801F7F1C() {}
