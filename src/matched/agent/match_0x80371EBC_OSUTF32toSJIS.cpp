// 0x80371EBC OSUTF32toSJIS (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 0,1; cmplw 0,3; bgt 0f; li 3,0; blr; 0:; lis 4,-32699; rlwinm 5,3,26,22,29; addi 0,4,-3104; add 4,0,5; lwz 4,0x0(4); cmplwi 4,0; beq 1f; rlwinm 0,3,1,23,30; lhzx 3,4,0; blr; 1:; li 3,0"
extern "C" int f_80371EBC() {}
