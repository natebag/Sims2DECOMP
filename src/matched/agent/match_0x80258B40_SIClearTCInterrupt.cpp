// 0x80258B40 SIClearTCInterrupt (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; addi 3,3,25600; lwz 0,0x34(3); oris 0,0,32768; clrlwi 0,0,30; stw 0,0x34(3)"
extern "C" void f_80258B40() {}
