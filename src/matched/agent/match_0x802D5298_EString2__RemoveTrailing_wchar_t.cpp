// 0x802D5298 EString2::RemoveTrailing(wchar_t) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; bl _s802D5298_0; mr. 0,3; mtspr 9,0; beq 2f; lwz 10,0x0(31); add 11,0,0; add 9,11,10; lhz 0,-2(9); cmpw 0,30; bne 2f; addi 0,11,-2; add 9,0,10; 0:; lhz 0,0x0(9); addi 9,9,-2; cmpw 0,30; bne 1f; bdnz 0b; 1:; addi 3,1,8; mfspr 5,9; mr 30,3; mr 4,31; bl _s802D5298_1; lwz 4,0x8(1); mr 3,31; bl _s802D5298_2; lwz 4,0x8(1); mr 3,30; bl _s802D5298_3; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802D5298_0();
extern "C" void _s802D5298_1();
extern "C" void _s802D5298_2();
extern "C" void _s802D5298_3();
extern "C" void f_802D5298() {}
