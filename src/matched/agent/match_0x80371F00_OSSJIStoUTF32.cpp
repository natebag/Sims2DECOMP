// 0x80371F00 OSSJIStoUTF32 (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-32699; rlwinm 5,3,0,16,31; rlwinm 3,3,26,22,29; addi 0,4,18400; add 3,0,3; lwz 3,0x0(3); cmplwi 3,0; beq 0f; rlwinm 0,5,1,23,30; lhzx 3,3,0; blr; 0:; li 3,0"
extern "C" int f_80371F00() {}
