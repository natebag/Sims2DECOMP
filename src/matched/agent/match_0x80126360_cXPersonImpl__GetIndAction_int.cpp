// 0x80126360 cXPersonImpl::GetIndAction(int, (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 5,0; bne 0f; lwz 0,0x534(3); cmpwi 0,0; beq 0f; addi 4,4,1; 0:; cmpwi 4,0; blt 1f; addi 9,3,304; lwz 3,0x2a8(9); lwz 0,0x2ac(9); subf 0,3,0; cmplw 4,0; blt 2f; 1:; li 3,0; blr; 2:; lis 0,-13108; add 3,3,4; ori 0,0,52429; mulhwu 0,3,0; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 3,0,3; mulli 3,3,68; add 3,9,3"
extern "C" int f_80126360() {}
