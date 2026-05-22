// 0x802BD8C0 EAStringC::StartWith(char (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; mr 3,31; bl _s802BD8C0_0; mr 5,3; lwz 3,0x0(30); lhz 0,0x2(3); cmplw 0,5; blt 0f; addi 3,3,8; mr 4,31; bl _s802BD8C0_1; subfic 0,3,0; adde 3,0,3; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802BD8C0_0();
extern "C" void _s802BD8C0_1();
extern "C" void f_802BD8C0() {}
