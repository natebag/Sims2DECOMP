// 0x803908AC GXSetProjectionv (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,-17352(13); lfs f0,0x0(3); fcmpu 0,f1,f0; bne 0f; li 0,0; b 1f; 0:; li 0,1; 1:; lwz 5,-17720(13); addi 3,3,4; stw 0,0x4d8(5); addi 6,5,1244; .long 0xE0430000; .long 0xE0230008; .long 0xE0030010; .long 0xF0460000; .long 0xF0260008; .long 0xF0060010; lis 4,-13311; li 0,16; lis 3,6; stb 0,-32768(4); addi 0,3,4128; stw 0,-32768(4); addi 3,4,-32768; .long 0xE0460000; .long 0xE0260008; .long 0xE0060010; .long 0xF0430000; .long 0xF0230000; .long 0xF0030000; lwz 3,0x4d8(5); li 0,1; stw 3,-32768(4); sth 0,0x2(5)"
extern "C" void f_803908AC() {}
