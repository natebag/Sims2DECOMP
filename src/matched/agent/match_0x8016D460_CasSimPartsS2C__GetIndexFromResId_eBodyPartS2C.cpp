// 0x8016D460 CasSimPartsS2C::GetIndexFromResId(eBodyPartS2C, (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 21,0x1c(1); stw 0,0x4c(1); mr 26,3; mr 27,4; mr 21,5; mr 29,6; mr 22,7; li 30,0; bl _s8016D460_0; mr 28,3; cmpw 30,28; bge 2f; lwz 23,0xc(29); addi 31,1,8; lwz 24,0x0(29); lwz 25,0x4(29); lwz 29,0x8(29); 0:; stw 24,0x8(1); mr 3,26; stw 25,0x4(31); mr 4,27; stw 29,0x8(31); mr 5,30; stw 23,0xc(31); mr 6,31; bl _s8016D460_1; cmpw 3,21; bne 1f; stw 30,0x0(22); li 3,1; b 3f; 1:; addi 30,30,1; cmpw 30,28; blt 0b; 2:; li 3,0; 3:; lwz 0,0x4c(1); mtspr 8,0; lmw 21,0x1c(1); addi 1,1,72"
extern "C" void _s8016D460_0();
extern "C" void _s8016D460_1();
extern "C" void f_8016D460() {}
