// 0x801F1C4C INVTarget::GrabModeCallbackImpl(InteractorModule::GrabManipulator::CallbackData (400 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 27,4; mr 31,3; lwz 0,0x0(27); cmpwi 0,2; beq 0f; ble 5f; cmpwi 0,3; bne 5f; li 0,1; stw 0,0x32ec(31); bl _s801F1C4C_0; bl _s801F1C4C_1; lwz 4,0x84(31); bl _s801F1C4C_2; mr 3,31; li 4,1; bl _s801F1C4C_3; b 5f; 0:; lwz 0,0x90(31); cmpwi 0,0; beq 5f; lwz 9,-21432(13); lwz 0,0x3c0(9); cmpwi 0,0; bne 5f; lwz 29,0xc(27); cmpwi 29,0; beq 5f; mr 3,29; bl _s801F1C4C_4; lwz 9,0x4(29); mr 26,3; lwz 0,0x464(9); lha 3,0x460(9); mtspr 8,0; add 3,29,3; blrl; lis 9,-32697; mr 28,3; lwz 0,0x61a8(9); cmpwi 0,0; beq 1f; li 28,1; 1:; cmpwi 28,0; beq 3f; lwz 9,0x4(29); lwz 30,0x90(31); lha 3,0x4b8(9); lwz 0,0x4bc(9); add 3,29,3; mtspr 8,0; blrl; mr 6,3; mr 4,26; mr 3,30; li 5,1; bl _s801F1C4C_5; mr. 28,3; beq 2f; lwz 9,0x4(29); lwz 30,0x90(31); lwz 0,0x4bc(9); lha 3,0x4b8(9); mtspr 8,0; add 3,29,3; blrl; mr 6,3; mr 4,26; mr 3,30; li 5,1; bl _s801F1C4C_6; li 0,1; stw 0,0x10(27); b 5f; 2:; addi 30,31,12892; li 5,1; mr 4,30; mr 3,31; bl _s801F1C4C_7; b 4f; 3:; addi 30,31,12892; mr 3,31; mr 4,30; bl _s801F1C4C_8; 4:; mr 3,30; bl _s801F1C4C_9; lwz 3,0x3298(31); cmpwi 3,0; beq 5f; bl _s801F1C4C_10; stw 28,0x3298(31); 5:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s801F1C4C_0();
extern "C" void _s801F1C4C_1();
extern "C" void _s801F1C4C_2();
extern "C" void _s801F1C4C_3();
extern "C" void _s801F1C4C_4();
extern "C" void _s801F1C4C_5();
extern "C" void _s801F1C4C_6();
extern "C" void _s801F1C4C_7();
extern "C" void _s801F1C4C_8();
extern "C" void _s801F1C4C_9();
extern "C" void _s801F1C4C_10();
extern "C" void f_801F1C4C() {}
