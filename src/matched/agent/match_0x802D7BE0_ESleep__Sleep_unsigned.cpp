// 0x802D7BE0 ESleep::Sleep(unsigned (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 11,-32768; lis 0,4194; lwz 9,0xf8(11); ori 0,0,19923; mr 30,3; lis 7,-32723; mulhwu 9,9,0; addi 3,30,24; addi 7,7,31520; rlwinm 9,9,24,8,31; mullw 4,4,9; mr 6,4; li 5,0; bl _s802D7BE0_0; mr 3,30; li 4,-1; bl _s802D7BE0_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D7BE0_0();
extern "C" void _s802D7BE0_1();
extern "C" void f_802D7BE0() {}
