// 0x800056F0 ESimsApp::UpdateAudio(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x450(3); cmpwi 0,0; bne 0f; lwz 3,-21492(13); cmpwi 3,0; beq 0f; bl _s800056F0_0; 0:; lwz 0,-31536(13); cmpwi 0,0; bne 1f; li 3,120; bl _s800056F0_1; bl _s800056F0_2; stw 3,-31536(13); 1:; lwz 3,-31536(13); bl _s800056F0_3; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800056F0_0();
extern "C" void _s800056F0_1();
extern "C" void _s800056F0_2();
extern "C" void _s800056F0_3();
extern "C" void f_800056F0() {}
