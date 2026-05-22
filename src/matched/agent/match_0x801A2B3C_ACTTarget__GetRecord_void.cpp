// 0x801A2B3C ACTTarget::GetRecord(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 8,3; li 10,0; li 3,0; addi 11,8,240; 0:; lwz 0,0x0(11); cmpwi 0,0; bne 1f; li 10,1; b 2f; 1:; addi 11,11,76; addi 3,3,1; 2:; cmpwi 7,3,17; xori 9,10,1; cror 31,30,28; mfcr 0; rlwinm 0,0,0,31,31; and. 7,0,9; bne 0b; cmpwi 10,0; beq 3f; mulli 3,3,76; addi 3,3,236; add 3,8,3; blr; 3:; li 3,0"
extern "C" int f_801A2B3C() {}
