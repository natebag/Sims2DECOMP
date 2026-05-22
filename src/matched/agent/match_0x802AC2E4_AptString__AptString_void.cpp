// 0x802AC2E4 AptString::AptString(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,1; bl _s802AC2E4_0; lis 11,-32700; lis 9,-32703; addi 9,9,2048; addi 0,11,-6476; stw 9,0x8(30); li 10,0; stw 0,0xc(30); mr 3,30; lhz 9,-6476(11); addi 9,9,1; sth 9,-6476(11); stw 10,0x10(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802AC2E4_0();
extern "C" void f_802AC2E4() {}
