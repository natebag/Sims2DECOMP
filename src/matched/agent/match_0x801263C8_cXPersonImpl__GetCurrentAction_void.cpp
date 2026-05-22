// 0x801263C8 cXPersonImpl::GetCurrentAction(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x534(3); cmpwi 0,0; beq 0f; addi 9,3,304; lis 0,-13108; lwz 11,0x2a8(9); ori 0,0,52429; mulhwu 0,11,0; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 11,0,11; mulli 11,11,68; add 3,9,11; blr; 0:; lis 9,-32696; addi 3,9,26596"
extern "C" int f_801263C8() {}
