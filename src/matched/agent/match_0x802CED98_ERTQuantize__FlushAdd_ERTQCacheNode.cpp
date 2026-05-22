// 0x802CED98 ERTQuantize::FlushAdd(ERTQCacheNode (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); mr 30,4; addi 29,1,16; lwz 0,0x0(30); mr 28,3; lbz 9,0x3(30); rlwinm 11,0,16,16,31; addi 4,1,8; rlwinm 0,0,24,8,31; mr 5,29; stb 9,0x8(1); stb 0,0x9(1); stb 11,0xa(1); bl _s802CED98_0; lwz 5,0x4(30); mr 3,28; mr 4,29; bl _s802CED98_1; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s802CED98_0();
extern "C" void _s802CED98_1();
extern "C" void f_802CED98() {}
