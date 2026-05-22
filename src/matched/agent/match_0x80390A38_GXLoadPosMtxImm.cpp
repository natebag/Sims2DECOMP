// 0x80390A38 GXLoadPosMtxImm (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 5,-13311; li 0,16; rlwinm 4,4,2,0,29; stb 0,-32768(5); oris 0,4,11; stw 0,-32768(5); addi 4,5,-32768; .long 0xE0A30000; .long 0xE0830008; .long 0xE0630010; .long 0xE0430018; .long 0xE0230020; .long 0xE0030028; .long 0xF0A40000; .long 0xF0840000; .long 0xF0640000; .long 0xF0440000; .long 0xF0240000; .long 0xF0040000"
extern "C" void f_80390A38() {}
