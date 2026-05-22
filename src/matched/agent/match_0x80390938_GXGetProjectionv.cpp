// 0x80390938 GXGetProjectionv (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-17720(13); lwz 0,0x4d8(4); cmplwi 0,0; beq 0f; lfs f0,-17348(13); b 1f; 0:; lfs f0,-17352(13); 1:; stfs f0,0x0(3); addi 4,3,4; lwz 3,-17720(13); addi 3,3,1244; .long 0xE0430000; .long 0xE0230008; .long 0xE0030010; .long 0xF0440000; .long 0xF0240008; .long 0xF0040010"
extern "C" void f_80390938() {}
