// 0x8035F220 ERTQuantize4D::FlushAdd(ERTQ4CacheNode (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 30,4; addi 9,1,24; lwz 0,0x0(30); mr 29,3; lbz 10,0x3(30); mr 4,9; rlwinm 8,0,8,24,31; rlwinm 11,0,24,8,31; stb 10,0x18(1); rlwinm 0,0,16,16,31; addi 5,1,8; stb 11,0x1(9); stb 0,0x2(9); stb 8,0x3(9); bl _s8035F220_0; lwz 5,0x4(30); mr 3,29; addi 4,1,8; bl _s8035F220_1; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s8035F220_0();
extern "C" void _s8035F220_1();
extern "C" void f_8035F220() {}
