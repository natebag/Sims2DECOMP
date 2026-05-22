// 0x80145874 QuickDataSoundInfo::QuickDataSoundInfo(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; lis 9,-32698; addi 9,9,19616; addi 28,30,4; lis 29,-32706; stw 9,0x0(30); addi 29,29,-10416; addi 4,30,12; li 5,64; mr 3,28; bl _s80145874_0; li 27,0; mr 3,28; mr 4,29; li 5,-1; bl _s80145874_1; stw 27,0x4c(30); addi 3,30,80; li 4,-1; li 5,0; bl _s80145874_2; lis 9,-32698; stw 27,0x58(30); addi 9,9,19504; mr 3,30; stw 9,0x0(30); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80145874_0();
extern "C" void _s80145874_1();
extern "C" void _s80145874_2();
extern "C" void f_80145874() {}
