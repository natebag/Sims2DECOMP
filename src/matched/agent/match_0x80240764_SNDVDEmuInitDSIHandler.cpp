// 0x80240764 SNDVDEmuInitDSIHandler (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32700; lwz 0,-23456(9); cmpwi 0,-32768; bne 0f; li 0,0; li 6,1; lis 4,-32694; lis 5,-32694; lis 8,-32694; li 11,-1; lis 10,-32694; lis 7,-32694; lis 9,-32694; stw 0,-26368(4); stw 11,-26364(8); stw 0,-26356(10); stb 6,-26352(9); stw 0,-26432(5); stb 6,-26351(7); bl _s80240764_0; lis 4,-32732; li 3,2; addi 4,4,1052; bl _s80240764_1; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80240764_0();
extern "C" void _s80240764_1();
extern "C" void f_80240764() {}
