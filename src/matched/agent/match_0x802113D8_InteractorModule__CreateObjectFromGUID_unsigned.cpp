// 0x802113D8 InteractorModule::CreateObjectFromGUID(unsigned (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 11,-21508(13); mr 4,3; lwz 9,0x0(11); lwz 0,0x7c(9); lha 3,0x78(9); mtspr 8,0; add 3,11,3; blrl; lwz 29,-21484(13); lwz 30,0x0(29); lha 0,0x50(30); addi 30,30,80; add 29,29,0; bl _s802113D8_0; lwz 0,0x4(30); mr 4,3; li 5,0; mr 3,29; mtspr 8,0; blrl; lwz 11,-21484(13); mr 4,3; lwz 9,0x0(11); lha 3,0x90(9); lwz 0,0x94(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802113D8_0();
extern "C" void f_802113D8() {}
