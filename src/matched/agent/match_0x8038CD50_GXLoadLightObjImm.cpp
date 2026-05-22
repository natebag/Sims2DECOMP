// 0x8038CD50 GXLoadLightObjImm (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cntlzw 0,4; subfic 0,0,31; rlwinm 5,0,4,25,27; lis 4,-13311; li 0,16; addi 5,5,1536; stb 0,-32768(4); oris 0,5,15; stwu 0,-32768(4); lwz 0,0xc(3); xor 6,6,6; .long 0xE0A30010; .long 0xE0830018; .long 0xE0630020; .long 0xE0430028; .long 0xE0230030; .long 0xE0030038; stw 6,0x0(4); stw 6,0x0(4); stw 6,0x0(4); stw 0,0x0(4); .long 0xF0A40000; .long 0xF0840000; .long 0xF0640000; .long 0xF0440000; .long 0xF0240000; .long 0xF0040000; lwz 3,-17720(13); li 0,1; sth 0,0x2(3)"
extern "C" void f_8038CD50() {}
