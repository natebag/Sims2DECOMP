// 0x803791E0 __AXClInit (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32690; li 4,0; addi 3,3,8544; stw 4,-22208(13); li 0,1; stw 4,-22224(13); stw 3,-22220(13); stw 0,-22212(13)"
extern "C" void f_803791E0() {}
