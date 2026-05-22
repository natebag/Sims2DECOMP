// 0x80392108 VMInit (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); stw 31,0x1c(1); stw 30,0x18(1); mr 30,5; stw 29,0x14(1); mr 29,4; stw 28,0x10(1); mr 28,3; lwz 0,-21876(13); cmpwi 0,0; bne 0f; bl _s80392108_0; rlwinm 5,28,20,12,31; li 6,1; lis 4,-32711; stw 6,-21876(13); addi 0,4,8868; mr 31,3; stw 29,-25224(13); mr 3,0; stw 30,-21888(13); stw 28,-21896(13); stw 5,-21884(13); bl _s80392108_1; bl _s80392108_2; bl _s80392108_3; bl _s80392108_4; mr 3,31; bl _s80392108_5; 0:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); mtspr 8,0; addi 1,1,32"
extern "C" void _s80392108_0();
extern "C" void _s80392108_1();
extern "C" void _s80392108_2();
extern "C" void _s80392108_3();
extern "C" void _s80392108_4();
extern "C" void _s80392108_5();
extern "C" void f_80392108() {}
