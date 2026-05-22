// 0x800BBC3C HouseImpl::SaveFile(iResFile (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 28,4; lwz 9,0x0(30); lwz 29,-32040(13); lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,30,3; blrl; lwz 5,-32032(13); mr 4,28; lha 6,-32036(13); mr 7,29; lwz 3,-21496(13); bl _s800BBC3C_0; lha 6,-32034(13); mr 7,29; lwz 5,-32028(13); mr 4,28; mr 3,30; bl _s800BBC3C_1; lwz 11,-21488(13); mr 5,29; mr 4,28; lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21484(13); mr 4,28; lwz 9,0x0(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; mr 4,28; li 3,146; bl _s800BBC3C_2; li 3,0; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800BBC3C_0();
extern "C" void _s800BBC3C_1();
extern "C" void _s800BBC3C_2();
extern "C" void f_800BBC3C() {}
