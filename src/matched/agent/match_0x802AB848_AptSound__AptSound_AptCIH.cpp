// 0x802AB848 AptSound::AptSound(AptCIH (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; li 4,21; bl _s802AB848_0; lis 9,-32703; addi 3,30,12; addi 9,9,8984; li 4,8; stw 9,0x8(30); bl _s802AB848_1; li 0,0; lis 9,-32703; stb 0,0x20(30); addi 9,9,-7384; li 10,0; stw 9,0x8(30); lwz 0,0x20(30); mr 3,30; stw 10,0x28(30); rlwinm 0,0,0,10,7; stw 0,0x20(30); lwz 9,0x4c(29); lwz 11,0x8(9); lwz 0,0x4(11); stw 10,0x2c(30); stw 0,0x24(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802AB848_0();
extern "C" void _s802AB848_1();
extern "C" void f_802AB848() {}
