// 0x80312648 EResPrefetch::DoCancel(EPrefetchMsg (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 10,3; li 0,0; stw 0,0x3dc(10); lis 11,-32702; stw 0,0x3e0(10); lis 9,-32692; stw 0,0x3e4(10); addi 3,9,-17464; stw 0,0x3ec(10); mr 31,4; stw 0,0x3e8(10); stw 0,0x3f0(10); stw 0,0x3f4(10); stw 0,0x404(10); stw 0,0x408(10); stw 0,0x40c(10); lfs f0,0x500(11); stw 0,0x414(10); stfs f0,0x410(10); lwz 0,0x8(3); cmpw 10,0; bne 0f; mr 4,10; bl _s80312648_0; 0:; lwz 3,0x10(31); bl _s80312648_1; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80312648_0();
extern "C" void _s80312648_1();
extern "C" void f_80312648() {}
