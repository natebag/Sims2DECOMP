// 0x802D43A0 EString2::MakeCopyFromChars(char (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; mr. 29,4; beq 0f; mr 3,29; bl _s802D43A0_0; mr 31,3; b 1f; 0:; li 31,0; 1:; cmpwi 31,0; beq 5f; addi 30,31,1; add 30,30,30; bl _s802D43A0_1; mr 4,30; li 5,0; bl _s802D43A0_2; mr. 3,3; beq 4f; li 11,0; add 10,31,31; cmpw 11,31; bge 3f; mr 9,3; 2:; lbzx 0,29,11; addi 11,11,1; extsb 0,0; cmpw 11,31; sth 0,0x0(9); addi 9,9,2; blt 2b; 3:; li 0,0; sthx 0,10,3; stw 3,0x0(28); b 6f; 4:; mr 3,28; bl _s802D43A0_3; b 6f; 5:; mr 3,28; bl _s802D43A0_4; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802D43A0_0();
extern "C" void _s802D43A0_1();
extern "C" void _s802D43A0_2();
extern "C" void _s802D43A0_3();
extern "C" void _s802D43A0_4();
extern "C" void f_802D43A0() {}
