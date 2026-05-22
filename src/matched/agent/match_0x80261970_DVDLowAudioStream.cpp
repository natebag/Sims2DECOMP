// 0x80261970 DVDLowAudioStream (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); li 0,0; stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 6,-23352(13); lis 6,-13312; addi 6,6,24576; stw 0,-23360(13); oris 0,3,57600; lis 3,-32694; stw 0,0x8(6); rlwinm 0,5,30,2,31; addi 31,3,-16848; stw 0,0xc(6); li 0,1; addi 3,31,0; stw 4,0x10(6); lis 4,-32768; stw 0,0x1c(6); lwz 0,0xf8(4); rlwinm 0,0,30,2,31; mulli 30,0,10; bl _s80261970_0; lis 3,-32730; addi 7,3,4036; addi 3,31,0; addi 6,30,0; li 5,0; bl _s80261970_1; lwz 0,0x24(1); li 3,1; lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80261970_0();
extern "C" void _s80261970_1();
extern "C" void f_80261970() {}
