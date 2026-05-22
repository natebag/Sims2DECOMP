// 0x8037882C __AXGetAuxBOutput (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,-22244(13); lis 4,-32690; addi 0,4,2784; mulli 4,5,1920; add 0,0,4; stw 0,0x0(3)"
extern "C" void f_8037882C() {}
