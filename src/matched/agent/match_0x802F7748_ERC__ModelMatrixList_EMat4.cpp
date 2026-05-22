// 0x802F7748 ERC::ModelMatrixList(EMat4 (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 29,5; lwz 9,0x70(31); mr 28,4; li 4,1; li 5,0; lwz 0,0x2b4(9); rlwinm 30,29,6,0,25; lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; mr 4,30; li 5,32; mr 3,31; bl _s802F7748_0; mr 0,3; stw 29,0x3c(31); stw 0,0x38(31); mr 4,28; mr 5,30; crxor 6,6,6; bl _s802F7748_1; li 11,4; li 0,255; mtspr 9,11; addi 9,31,48; 0:; stw 0,0x0(9); addi 9,9,-4; bdnz 0b; li 0,1; stw 0,0x34(31); stw 0,0x40(31); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802F7748_0();
extern "C" void _s802F7748_1();
extern "C" void f_802F7748() {}
