// 0x8030A5D0 PutChar(int) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-26680(13); lwz 0,-26676(13); cmpw 9,0; bne 0f; li 0,1; stw 0,-26672(13); blr; 0:; addi 11,13,-26680; lwz 9,0x0(11); stb 3,0x0(9); addi 9,9,1; stw 9,0x0(11)"
extern "C" void f_8030A5D0() {}
