// 0x8012C72C cXPersonImpl::GetCurrentInteractionNC(void) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,3,304; lis 0,-13108; lwz 9,0x2a8(3); ori 0,0,52429; mulhwu 0,9,0; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 9,0,9; mulli 9,9,68; add 3,3,9"
extern "C" int f_8012C72C() {}
