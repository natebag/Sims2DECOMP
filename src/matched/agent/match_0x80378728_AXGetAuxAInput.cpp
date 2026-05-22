// 0x80378728 __AXGetAuxAInput (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-22280(13); cmplwi 0,0; beq 0f; lwz 5,-22248(13); lis 4,-32690; addi 0,4,-2976; mulli 4,5,1920; add 0,0,4; stw 0,0x0(3); blr; 0:; li 0,0; stw 0,0x0(3)"
extern "C" void f_80378728() {}
