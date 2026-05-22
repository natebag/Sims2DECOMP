// 0x80267358 AISetStreamVolRight (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-13312; addi 4,4,27648; lwz 0,0x4(4); rlwinm 0,0,0,24,15; rlwimi 0,3,8,16,23; stw 0,0x4(4)"
extern "C" void f_80267358() {}
