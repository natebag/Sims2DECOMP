// 0x80390808 GXSetProjection (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,-17720(13); cmpwi 4,1; stw 4,0x4d8(5); lfs f0,0x0(3); stfs f0,0x4dc(5); lfs f0,0x14(3); stfs f0,0x4e4(5); lfs f0,0x28(3); stfs f0,0x4ec(5); lfs f0,0x2c(3); stfs f0,0x4f0(5); bne 0f; lfs f0,0xc(3); stfs f0,0x4e0(5); lfs f0,0x1c(3); stfs f0,0x4e8(5); b 1f; 0:; lfs f0,0x8(3); stfs f0,0x4e0(5); lfs f0,0x18(3); stfs f0,0x4e8(5); 1:; lis 5,-13311; lwz 4,-17720(13); li 0,16; lis 3,6; stb 0,-32768(5); addi 0,3,4128; stw 0,-32768(5); addi 6,5,-32768; addi 3,4,1244; .long 0xE0430000; .long 0xE0230008; .long 0xE0030010; .long 0xF0460000; .long 0xF0260000; .long 0xF0060000; lwz 3,0x4d8(4); li 0,1; stw 3,-32768(5); sth 0,0x2(4)"
extern "C" void f_80390808() {}
