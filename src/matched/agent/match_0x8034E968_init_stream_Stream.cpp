// 0x8034E968 init_stream(Stream (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,1; lwz 0,0x74(31); lis 11,2; li 8,0; ori 9,9,16768; oris 0,0,128; li 10,1; rlwinm 0,0,0,11,9; ori 11,11,12960; stw 0,0x74(31); ori 8,8,41152; stw 9,0x6c(31); lbz 0,0x75(31); li 9,0; stb 5,0x14(31); ori 9,9,41152; andi. 0,0,247; stb 6,0x15(31); stb 0,0x75(31); stb 10,0x74(31); lbz 0,0x75(31); stw 11,0x70(31); ori 0,0,16; stw 4,0x10(31); stb 0,0x75(31); stw 8,0x60(31); lwz 0,0xc(4); stw 0,0x64(31); cmplw 0,9; bge 0f; lwz 3,0x68(31); mr 30,0; subf 5,30,8; li 4,0; add 3,3,30; bl _s8034E968_0; b 1f; 0:; li 30,0; ori 30,30,41152; 1:; li 0,2; mr 3,30; stw 0,0x0(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8034E968_0();
extern "C" void f_8034E968() {}
