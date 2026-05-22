// 0x803907C0 __GXSetProjection (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-13311; lwz 3,-17720(13); li 0,16; lis 5,6; stb 0,-32768(4); addi 0,5,4128; stw 0,-32768(4); addi 6,4,-32768; addi 5,3,1244; .long 0xE0450000; .long 0xE0250008; .long 0xE0050010; .long 0xF0460000; .long 0xF0260000; .long 0xF0060000; lwz 0,0x4d8(3); stw 0,-32768(4)"
extern "C" void f_803907C0() {}
