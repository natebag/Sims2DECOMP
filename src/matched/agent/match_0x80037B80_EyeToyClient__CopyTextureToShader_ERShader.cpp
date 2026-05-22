// 0x80037B80 EyeToyClient::CopyTextureToShader(ERShader (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); mr 9,3; mr 28,4; lwz 3,0x14(9); cmpwi 3,0; bne 0f; lwz 9,0x18(9); li 3,0; cmpwi 9,0; beq 0f; lwz 3,0x14(9); 0:; li 4,0; bl _s80037B80_0; mr 31,3; addi 29,1,8; lwz 9,0x24(31); addi 30,1,12; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; mr 3,28; bl _s80037B80_1; lwz 9,0x24(28); mr 26,3; li 4,1; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,28,3; blrl; mr 3,31; bl _s80037B80_2; lwz 9,0x24(31); mr 25,3; li 4,2; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x24(28); li 4,0; mr 5,29; mr 6,30; lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,28,3; blrl; lwz 9,0x24(31); mr 27,3; mr 5,29; mr 6,30; lwz 0,0x44(9); li 4,0; lha 3,0x40(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0x8(1); li 10,0; lwz 11,0xc(1); rlwinm 9,0,1,31,31; add 0,0,9; srawi 0,0,1; mullw 11,0,11; cmplw 10,11; bge 2f; li 9,0; 1:; lhzx 0,9,27; addi 10,10,1; cmplw 10,11; ori 0,0,32768; sthx 0,9,3; addi 9,9,2; blt 1b; 2:; lwz 9,0x24(28); lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,28,3; blrl; mr 4,26; mr 3,28; bl _s80037B80_3; lwz 9,0x24(31); lha 3,0x70(9); lwz 0,0x74(9); add 3,31,3; mtspr 8,0; blrl; mr 3,31; mr 4,25; bl _s80037B80_4; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"
extern "C" void _s80037B80_0();
extern "C" void _s80037B80_1();
extern "C" void _s80037B80_2();
extern "C" void _s80037B80_3();
extern "C" void _s80037B80_4();
extern "C" void f_80037B80() {}
