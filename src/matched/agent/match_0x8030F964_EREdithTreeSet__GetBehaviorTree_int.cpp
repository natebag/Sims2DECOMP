// 0x8030F964 EREdithTreeSet::GetBehaviorTree(int) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x18(3); cmpwi 9,0; bne 1f; li 3,0; blr; 0:; lwz 3,0x8(7); blr; 1:; addi 10,9,-1; li 8,0; cmplw 8,10; bgt 5f; lwz 3,0x1c(3); 2:; add 0,8,10; rlwinm 11,0,31,1,31; mulli 9,11,12; lwzx 0,9,3; add 7,9,3; cmpw 4,0; beq 0b; bge 3f; addi 10,11,-1; b 4f; 3:; addi 8,11,1; 4:; cmplw 8,10; ble 2b; 5:; li 3,0"
extern "C" int f_8030F964() {}
