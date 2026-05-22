// 0x8013DA14 SeqResFile::AddOpenSpec(int, (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 27,3; li 31,0; addi 9,27,208; mr 11,4; lwzx 0,9,31; mr 26,5; cmpwi 0,0; beq 1f; 0:; lwzu 0,0x14(9); addi 31,31,1; cmpwi 0,0; bne 0b; 1:; cmpwi 31,7; bgt 2f; cmpwi 11,4; bgt 2f; cmpwi 11,0; blt 2f; mulli 29,31,20; addi 30,1,8; addi 28,27,208; addi 4,30,8; li 5,8; mr 3,30; stwx 11,28,29; bl _s8013DA14_0; mr 4,26; mr 3,30; li 5,-1; bl _s8013DA14_1; add 29,29,27; mr 4,30; addi 3,29,212; bl _s8013DA14_2; addi 0,31,1; li 9,0; mulli 0,0,20; stwx 9,28,0; 2:; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"
extern "C" void _s8013DA14_0();
extern "C" void _s8013DA14_1();
extern "C" void _s8013DA14_2();
extern "C" void f_8013DA14() {}
