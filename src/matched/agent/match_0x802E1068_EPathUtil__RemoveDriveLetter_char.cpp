// 0x802E1068 EPathUtil::RemoveDriveLetter(char (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; mr 3,31; li 4,58; bl _s802E1068_0; mr. 3,3; beq 0f; addi 0,31,1; cmpw 3,0; bne 0f; addi 4,3,1; mr 3,30; bl _s802E1068_1; b 1f; 0:; cmpw 30,31; beq 1f; mr 4,31; mr 3,30; bl _s802E1068_2; 1:; mr 3,30; bl _s802E1068_3; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E1068_0();
extern "C" void _s802E1068_1();
extern "C" void _s802E1068_2();
extern "C" void _s802E1068_3();
extern "C" void f_802E1068() {}
