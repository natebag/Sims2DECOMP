// 0x802172FC InteractorModule::InteractorVisualizer::InteractorOrderTableCallback(ELevelDrawData (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 0,0x98(30); stw 0,-28504(13); bl _s802172FC_0; lwz 4,0x18(29); li 5,-1; bl _s802172FC_1; mr. 31,3; beq 0f; bl _s802172FC_2; lwz 0,0x1c(29); mr 4,3; lwz 9,0x5c(31); stw 0,0x4c(31); lwz 0,0xbc(9); lha 3,0xb8(9); mtspr 8,0; add 3,31,3; blrl; li 0,0; stw 0,0xb8(30); stw 0,0xac(30); stw 0,0xb4(30); stw 0,0xa8(30); stw 0,0xb0(30); 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802172FC_0();
extern "C" void _s802172FC_1();
extern "C" void _s802172FC_2();
extern "C" void f_802172FC() {}
