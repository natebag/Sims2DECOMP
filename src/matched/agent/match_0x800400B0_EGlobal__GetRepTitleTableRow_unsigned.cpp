// 0x800400B0 EGlobal::GetRepTitleTableRow(unsigned (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; lwz 3,0xe8(3); lis 4,-32707; li 31,0; addi 4,4,10276; bl _s800400B0_0; mr. 3,3; li 9,0; beq 0f; mr 9,3; 0:; cmpwi 9,0; beq 4f; lwz 0,0xc(9); li 11,0; lwz 9,0x4(9); cmpw 31,0; bge 3f; mr 8,0; li 10,0; 1:; cmpwi 31,0; mulli 3,11,28; bne 2f; add 31,9,10; 2:; lwzx 0,3,9; add 3,3,9; cmpw 0,30; beq 5f; cmplw 0,30; bgt 3f; addi 11,11,1; mr 31,3; addi 10,10,28; cmpw 11,8; blt 1b; 3:; mr 3,31; b 5f; 4:; li 3,0; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800400B0_0();
extern "C" void f_800400B0() {}
