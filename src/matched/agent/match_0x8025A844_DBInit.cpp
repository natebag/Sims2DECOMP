// 0x8025A844 DBInit (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-32768; addi 0,4,64; lis 3,-32730; stw 0,-23520(13); addi 3,3,-22320; addis 0,3,-32768; stw 0,0x48(4); li 0,1; stw 0,-23516(13)"
extern "C" void f_8025A844() {}
