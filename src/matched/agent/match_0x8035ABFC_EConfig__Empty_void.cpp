// 0x8035ABFC EConfig::Empty(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; addi 29,28,8; lwz 9,0x4(29); b 2f; 0:; lwz 0,0x8(29); lwz 31,0x0(9); cmpwi 0,0; lwz 30,0x4(9); beq 1f; cmpwi 31,0; beq 1f; lwz 4,0x0(31); mr 3,31; bl _s8035ABFC_0; mr 3,31; bl _s8035ABFC_1; 1:; mr 9,30; 2:; li 0,1; cmpwi 9,0; bne 3f; li 0,0; 3:; cmpwi 0,0; bne 0b; mr 3,29; bl _s8035ABFC_2; addi 3,28,20; bl _s8035ABFC_3; li 0,1; stw 0,0x0(28); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8035ABFC_0();
extern "C" void _s8035ABFC_1();
extern "C" void _s8035ABFC_2();
extern "C" void _s8035ABFC_3();
extern "C" void f_8035ABFC() {}
