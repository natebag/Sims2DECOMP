// 0x801843A8 ActionMenu::CloseMenu(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; lbz 0,0x9(9); cmpwi 0,4; beq 0f; cmpwi 0,2; beq 0f; cmpwi 0,5; beq 0f; cmpwi 0,6; bne 1f; 0:; li 0,9; mr 3,9; stb 0,0x9(9); bl _s801843A8_0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801843A8_0();
extern "C" void f_801843A8() {}
