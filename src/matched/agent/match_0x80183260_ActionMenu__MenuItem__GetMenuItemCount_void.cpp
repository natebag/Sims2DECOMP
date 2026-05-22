// 0x80183260 ActionMenu::MenuItem::GetMenuItemCount(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); bl _s80183260_0; li 31,1; mr. 3,3; beq 1f; 0:; bl _s80183260_1; addi 31,31,1; mr. 3,3; bne 0b; 1:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80183260_0();
extern "C" void _s80183260_1();
extern "C" void f_80183260() {}
