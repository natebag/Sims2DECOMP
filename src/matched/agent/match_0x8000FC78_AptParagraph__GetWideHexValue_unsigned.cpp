// 0x8000FC78 AptParagraph::GetWideHexValue(unsigned (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); mr 28,4; mr 29,6; mr 30,5; mr 3,28; bl _s8000FC78_0; li 31,0; add 30,30,30; mr 5,29; addi 3,1,8; add 4,28,30; bl _s8000FC78_1; add 0,29,29; addi 9,1,8; sthx 31,9,0; li 11,1; addic. 29,29,-1; blt 4f; add 0,29,29; add 10,0,9; 0:; lhz 9,0x0(10); addi 10,10,-2; addi 0,9,-48; cmplwi 0,9; ble 2f; addi 0,9,-65; cmplwi 0,5; bgt 1f; addi 0,9,-55; b 2f; 1:; addi 0,9,-97; cmplwi 0,5; bgt 3f; addi 0,9,-87; 2:; mullw 0,0,11; add 31,31,0; 3:; rlwinm 11,11,4,0,27; addic. 29,29,-1; bge 0b; 4:; mr 3,31; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s8000FC78_0();
extern "C" void _s8000FC78_1();
extern "C" void f_8000FC78() {}
