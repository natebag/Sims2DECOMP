// 0x80393D58 __THPRestartDefinition (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-21552(13); li 0,1; stb 0,0x6a9(3); lwz 4,-21552(13); lwz 3,0x69c(4); addi 0,3,2; stw 0,0x69c(4); lwz 5,-21552(13); lwz 4,0x69c(5); lbz 3,0x0(4); lbz 0,0x1(4); rlwimi 0,3,8,16,23; sth 0,0x6aa(5); lwz 4,-21552(13); lwz 3,0x69c(4); addi 0,3,2; stw 0,0x69c(4); lwz 3,-21552(13); lhz 0,0x6aa(3); sth 0,0x6ac(3)"
extern "C" void f_80393D58() {}
