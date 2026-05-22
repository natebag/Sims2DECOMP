// 0x803125D4 EResPrefetch::ReleasedBuffer(EScratchBuffUser (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 4,3; li 0,0; stw 0,0x3dc(4); lis 11,-32702; stw 0,0x3e0(4); lis 9,-32692; stw 0,0x3e4(4); addi 3,9,-17464; stw 0,0x3ec(4); stw 0,0x3e8(4); stw 0,0x3f0(4); stw 0,0x3f4(4); stw 0,0x404(4); stw 0,0x408(4); stw 0,0x40c(4); lfs f0,0x4fc(11); stw 0,0x414(4); stfs f0,0x410(4); lwz 0,0x8(3); cmpw 4,0; bne 0f; bl _s803125D4_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s803125D4_0();
extern "C" void f_803125D4() {}
