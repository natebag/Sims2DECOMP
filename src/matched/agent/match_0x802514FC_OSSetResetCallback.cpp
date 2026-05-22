// 0x802514FC OSSetResetCallback (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; stw 30,0x10(1); bl _s802514FC_0; lwz 30,-23616(13); cmplwi 31,0; stw 31,-23616(13); mr 31,3; beq 0f; li 0,2; lis 3,-13312; stw 0,0x3000(3); li 3,512; bl _s802514FC_1; b 1f; 0:; li 3,512; bl _s802514FC_2; 1:; mr 3,31; bl _s802514FC_3; mr 3,30; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s802514FC_0();
extern "C" void _s802514FC_1();
extern "C" void _s802514FC_2();
extern "C" void _s802514FC_3();
extern "C" void f_802514FC() {}
