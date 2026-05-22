// 0x80390EFC GXGetScissor (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 8,-17720(13); lwz 7,0xf8(8); lwz 8,0xfc(8); rlwinm 9,7,20,21,31; addi 0,9,-342; stw 0,0x0(3); rlwinm 7,7,0,21,31; addi 3,7,-342; stw 3,0x0(4); rlwinm 0,8,20,21,31; subf 3,9,0; addi 0,3,1; rlwinm 4,8,0,21,31; stw 0,0x0(5); subf 3,7,4; addi 0,3,1; stw 0,0x0(6)"
extern "C" void f_80390EFC() {}
