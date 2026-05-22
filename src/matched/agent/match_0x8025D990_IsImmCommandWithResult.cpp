// 0x8025D990 IsImmCommandWithResult (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 0,3,-9; cmplwi 0,3; bgt 0f; li 3,1; blr; 0:; lis 4,-32700; lwzu 0,-14372(4); cmplw 3,0; bne 1f; li 3,1; blr; 1:; lwzu 0,0x4(4); cmplw 3,0; bne 2f; li 3,1; blr; 2:; lwz 0,0x4(4); cmplw 3,0; bne 3f; li 3,1; blr; 3:; li 3,0"
extern "C" int f_8025D990() {}
