// 0x8035AC94 EConfig::GetNextLabelAndValue(EString (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 28,4; mr 27,5; li 0,1; mr. 6,6; bne 0f; li 0,0; 0:; cmpwi 0,0; bne 1f; lwz 6,0x8(3); 1:; cmpwi 6,0; beq 4f; addi 26,1,8; 2:; lwz 31,0x0(6); li 4,61; lwz 29,0x8(6); li 5,0; mr 3,31; bl _s8035AC94_0; mr 30,3; cmpwi 30,-1; beq 3f; lwz 9,0x0(31); lbz 0,0x0(9); extsb 0,0; cmpwi 0,59; beq 3f; cmpwi 0,35; beq 3f; addi 3,1,8; mr 5,30; mr 4,31; bl _s8035AC94_1; lwz 4,0x8(1); mr 3,28; bl _s8035AC94_2; lwz 4,0x8(1); mr 3,26; bl _s8035AC94_3; lwz 0,0x0(31); addi 4,30,1; mr 3,27; add 4,0,4; bl _s8035AC94_4; mr 3,29; b 5f; 3:; mr. 6,29; bne 2b; 4:; li 3,0; 5:; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s8035AC94_0();
extern "C" void _s8035AC94_1();
extern "C" void _s8035AC94_2();
extern "C" void _s8035AC94_3();
extern "C" void _s8035AC94_4();
extern "C" void f_8035AC94() {}
