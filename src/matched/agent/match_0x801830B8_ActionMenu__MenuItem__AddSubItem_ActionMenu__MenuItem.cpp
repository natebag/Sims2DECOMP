// 0x801830B8 ActionMenu::MenuItem::AddSubItem(ActionMenu::MenuItem (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 9,3; mr 30,4; lwz 3,0x5c(9); cmpwi 3,0; bne 1f; stw 30,0x5c(9); b 2f; 0:; mr 3,31; bl _s801830B8_0; 1:; mr 31,3; mr 3,31; bl _s801830B8_1; cmpwi 3,0; bne 0b; mr 3,31; mr 4,30; bl _s801830B8_2; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801830B8_0();
extern "C" void _s801830B8_1();
extern "C" void _s801830B8_2();
extern "C" void f_801830B8() {}
