// 0x8025557C GetLeapDays (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,1; bge 0f; li 3,0; b 1f; 0:; lis 4,20972; addi 0,3,-1; addi 4,4,-31457; mulhw 0,4,0; srawi 5,0,7; srawi 4,0,5; addi 0,3,3; rlwinm 3,4,1,31,31; srawi 0,0,2; rlwinm 6,5,1,31,31; add 3,4,3; addze 0,0; add 4,5,6; subf 0,3,0; add 3,4,0; 1:"
extern "C" int f_8025557C() {}
