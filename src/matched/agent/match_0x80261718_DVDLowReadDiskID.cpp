// 0x80261718 DVDLowReadDiskID (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 8,0; stw 0,0x4(1); lis 5,-22528; addi 0,5,64; stwu 1,-24(1); li 6,32; lis 5,-32768; stw 31,0x14(1); stw 30,0x10(1); stw 4,-23352(13); lis 4,-13312; addi 7,4,24576; stw 8,-23360(13); stw 0,0x6008(4); lis 4,-32694; li 0,3; stw 8,0xc(7); addi 31,4,-16848; stw 6,0x10(7); stw 3,0x14(7); mr 3,31; stw 6,0x18(7); stw 0,0x1c(7); lwz 0,0xf8(5); rlwinm 0,0,30,2,31; mulli 30,0,10; bl _s80261718_0; lis 3,-32730; addi 7,3,4036; addi 3,31,0; addi 6,30,0; li 5,0; bl _s80261718_1; lwz 0,0x1c(1); li 3,1; lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80261718_0();
extern "C" void _s80261718_1();
extern "C" void f_80261718() {}
