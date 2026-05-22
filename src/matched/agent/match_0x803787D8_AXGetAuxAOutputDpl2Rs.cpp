// 0x803787D8 __AXGetAuxAOutputDpl2Rs (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,-22244(13); lis 4,-32690; addi 0,4,2784; mulli 4,5,1920; add 4,0,4; addi 0,4,1280; stw 0,0x0(3)"
extern "C" void f_803787D8() {}
