// 0x802FB244 ESubModel::BuildDisplayList(bool, (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f30,0x20(1); stfd f31,0x28(1); stmw 26,0x8(1); stw 0,0x34(1); mr 30,3; li 31,0; lwz 0,0x4(30); mr 26,4; mr 27,5; mr 28,6; fmr f30,f1; cmpw 31,0; fmr f31,f2; bge 1f; li 29,0; 0:; lwz 3,0x0(30); mr 4,26; mr 5,27; mr 6,28; add 3,3,29; fmr f1,f30; fmr f2,f31; addi 31,31,1; bl _s802FB244_0; addi 29,29,112; lwz 0,0x4(30); cmpw 31,0; blt 0b; 1:; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x8(1); lfd f30,0x20(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s802FB244_0();
extern "C" void f_802FB244() {}
