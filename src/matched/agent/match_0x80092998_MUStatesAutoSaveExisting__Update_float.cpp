// 0x80092998 MUStatesAutoSaveExisting::Update(float) (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; lwz 9,0x8(31); lwz 0,0x90(9); cmpwi 0,0; bne 0f; li 4,8; bl _s80092998_0; li 0,1; stw 0,0x1c(31); b 7f; 0:; cmpwi 0,1; bne 5f; lwz 0,0x1c(31); cmpwi 0,1; bne 4f; lis 9,-32696; li 0,0; lwz 3,0x58d8(9); addi 4,1,8; stw 0,0x8(1); bl _s80092998_1; lwz 0,0x8(1); cmpwi 0,0; bne 1f; lwz 9,0x8(31); li 4,18; lwz 3,0x98(9); bl _s80092998_2; b 3f; 1:; lwz 9,0x20(31); addi 9,9,1; cmpwi 9,3; stw 9,0x20(31); ble 2f; lwz 11,0x8(31); li 0,5; li 4,12; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80092998_3; mr 3,31; li 4,14; bl _s80092998_4; li 0,3; stw 0,0x1c(31); b 7f; 2:; lwz 11,0x8(31); li 0,6; li 4,7; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80092998_5; 3:; mr 3,31; li 4,14; bl _s80092998_6; li 0,2; stw 0,0x1c(31); b 7f; 4:; cmpwi 0,3; bne 7f; bl _s80092998_7; lwz 3,0x8(31); li 4,1; bl _s80092998_8; b 7f; 5:; cmpwi 0,2; bne 7f; lwz 3,0x1c(31); cmpwi 3,1; bne 6f; mr 3,9; li 4,2; bl _s80092998_9; b 7f; 6:; addi 0,3,-2; cmplwi 0,1; bgt 7f; li 0,0; stw 0,0x90(9); 7:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s80092998_0();
extern "C" void _s80092998_1();
extern "C" void _s80092998_2();
extern "C" void _s80092998_3();
extern "C" void _s80092998_4();
extern "C" void _s80092998_5();
extern "C" void _s80092998_6();
extern "C" void _s80092998_7();
extern "C" void _s80092998_8();
extern "C" void _s80092998_9();
extern "C" void f_80092998() {}
