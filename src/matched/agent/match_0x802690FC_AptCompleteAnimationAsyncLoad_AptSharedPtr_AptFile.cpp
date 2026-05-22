// 0x802690FC AptCompleteAnimationAsyncLoad(AptSharedPtr<AptFile>, (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; mr 27,4; lwz 3,0x0(31); mr 29,5; mr 28,6; addi 30,1,8; stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802690FC_0; 0:; lwz 3,-23000(13); mr 4,30; mr 5,27; mr 6,29; mr 7,28; bl _s802690FC_1; lwz 3,0x0(31); cmpwi 3,0; beq 1f; bl _s802690FC_2; cmpwi 3,0; bne 1f; lwz 3,0x0(31); bl _s802690FC_3; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s802690FC_0();
extern "C" void _s802690FC_1();
extern "C" void _s802690FC_2();
extern "C" void _s802690FC_3();
extern "C" void f_802690FC() {}
