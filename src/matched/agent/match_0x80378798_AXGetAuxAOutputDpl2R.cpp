// 0x80378798 __AXGetAuxAOutputDpl2R (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,-22244(13); lis 4,-32690; addi 0,4,-2976; mulli 4,5,1920; add 4,0,4; addi 0,4,640; stw 0,0x0(3)"
extern "C" void f_80378798() {}
