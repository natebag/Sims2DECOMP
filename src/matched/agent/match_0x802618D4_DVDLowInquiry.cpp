// 0x802618D4 DVDLowInquiry (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 6,32; stw 0,0x4(1); li 0,0; lis 5,-32768; stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); stw 4,-23352(13); lis 4,-13312; addi 7,4,24576; stw 0,-23360(13); lis 0,4608; stw 0,0x6008(4); lis 4,-32694; li 0,3; stw 6,0x10(7); addi 31,4,-16848; stw 3,0x14(7); addi 3,31,0; stw 6,0x18(7); stw 0,0x1c(7); lwz 0,0xf8(5); rlwinm 0,0,30,2,31; mulli 30,0,10; bl _s802618D4_0; lis 3,-32730; addi 7,3,4036; addi 3,31,0; addi 6,30,0; li 5,0; bl _s802618D4_1; lwz 0,0x1c(1); li 3,1; lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s802618D4_0();
extern "C" void _s802618D4_1();
extern "C" void f_802618D4() {}
