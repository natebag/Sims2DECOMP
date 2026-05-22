// 0x802BD924 EAStringC::EndWith(char (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 9,0x0(31); mr 3,30; lhz 29,0x2(9); bl _s802BD924_0; mr 0,3; cmplw 29,0; blt 0f; lwz 3,0x0(31); mr 5,0; mr 4,30; addi 3,3,8; add 3,3,29; subf 3,0,3; bl _s802BD924_1; subfic 0,3,0; adde 3,0,3; b 1f; 0:; li 3,0; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802BD924_0();
extern "C" void _s802BD924_1();
extern "C" void f_802BD924() {}
