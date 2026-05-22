// 0x80116378 TrackDataReader::ReadCommand(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 31,0x0(30); cmpwi 31,0; bne 0f; bl _s80116378_0; li 0,12; stb 31,-24137(13); stb 0,-24140(13); addi 3,13,-24140; stb 31,-24139(13); stb 31,-24138(13); b 2f; 0:; lwz 0,0x18(31); lwz 9,0x14(31); lwz 11,0x4(30); subf 0,9,0; srawi 0,0,2; cmplw 11,0; blt 1f; mr 3,30; bl _s80116378_1; lwz 9,0x0(30); lwz 0,0x14(9); lwz 3,0x18(9); subf 3,0,3; rlwinm 3,3,0,0,29; addi 3,3,-4; add 3,0,3; b 2f; 1:; addi 0,11,1; rlwinm 9,11,2,0,29; stw 0,0x4(30); lwz 3,0x14(31); add 3,3,9; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80116378_0();
extern "C" void _s80116378_1();
extern "C" void f_80116378() {}
