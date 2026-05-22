// 0x80378ADC __AXGetCommandListAddress (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,-22224(13); lis 3,-32690; addi 4,3,8544; addi 0,5,1; stw 0,-22224(13); mulli 3,5,768; lwz 0,-22224(13); add 3,4,3; rlwinm 0,0,0,31,31; stw 0,-22224(13); lwz 0,-22224(13); mulli 0,0,768; add 0,4,0; stw 0,-22220(13)"
extern "C" void f_80378ADC() {}
