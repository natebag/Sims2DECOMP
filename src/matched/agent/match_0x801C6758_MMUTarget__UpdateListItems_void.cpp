// 0x801C6758 MMUTarget::UpdateListItems(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x8c(3); cmpwi 0,0; beq 0f; cmpwi 0,1; bne 1f; 0:; bl _s801C6758_0; b 2f; 1:; cmpwi 0,2; bne 2f; bl _s801C6758_1; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801C6758_0();
extern "C" void _s801C6758_1();
extern "C" void f_801C6758() {}
