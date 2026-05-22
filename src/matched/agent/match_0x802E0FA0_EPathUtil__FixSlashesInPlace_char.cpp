// 0x802E0FA0 EPathUtil::FixSlashesInPlace(char (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 4,92; bl _s802E0FA0_0; mr. 9,3; beq 1f; li 30,47; 0:; mr 3,9; stb 30,0x0(9); li 4,92; bl _s802E0FA0_1; mr. 9,3; bne 0b; 1:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E0FA0_0();
extern "C" void _s802E0FA0_1();
extern "C" void f_802E0FA0() {}
