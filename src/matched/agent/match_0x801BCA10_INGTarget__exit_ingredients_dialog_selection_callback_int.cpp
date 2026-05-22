// 0x801BCA10 INGTarget::exit_ingredients_dialog_selection_callback(int) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 4,0; bne 0f; li 4,0; bl _s801BCA10_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801BCA10_0();
extern "C" void f_801BCA10() {}
