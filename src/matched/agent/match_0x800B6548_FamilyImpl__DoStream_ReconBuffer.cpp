// 0x800B6548 FamilyImpl::DoStream(ReconBuffer (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 30,4; mr 29,5; mr 3,30; addi 4,31,12; li 5,1; bl _s800B6548_0; addi 28,31,4; li 5,1; mr 3,30; addi 4,31,16; bl _s800B6548_1; lwz 9,0x0(31); lwz 4,0x14(31); lwz 0,0xd4(9); lha 3,0xd0(9); mtspr 8,0; add 3,31,3; blrl; mr 3,30; addi 4,31,20; li 5,1; bl _s800B6548_2; mr 3,30; addi 4,31,24; li 5,1; bl _s800B6548_3; mr 3,30; addi 4,31,28; li 5,1; bl _s800B6548_4; mr 3,30; addi 4,31,52; li 5,1; bl _s800B6548_5; lwz 4,0x24(31); mr 6,29; addi 3,31,36; mr 5,30; bl _s800B6548_6; mr 3,30; mr 4,28; bl _s800B6548_7; lwz 0,0xc(30); cmpwi 0,0; bne 1f; lwz 9,0xc(31); addi 9,9,-13; cmplwi 9,3; bgt 0f; lwz 3,-21432(13); mr 4,28; bl _s800B6548_8; b 1f; 0:; lwz 3,-21432(13); mr 4,28; bl _s800B6548_9; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800B6548_0();
extern "C" void _s800B6548_1();
extern "C" void _s800B6548_2();
extern "C" void _s800B6548_3();
extern "C" void _s800B6548_4();
extern "C" void _s800B6548_5();
extern "C" void _s800B6548_6();
extern "C" void _s800B6548_7();
extern "C" void _s800B6548_8();
extern "C" void _s800B6548_9();
extern "C" void f_800B6548() {}
