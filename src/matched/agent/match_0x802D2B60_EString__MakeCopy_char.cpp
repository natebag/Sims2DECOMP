// 0x802D2B60 EString::MakeCopy(char (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr. 28,4; beq 0f; mr 3,28; bl _s802D2B60_0; b 1f; 0:; li 3,0; 1:; cmpwi 3,0; beq 2f; addi 30,3,1; mr 3,29; mr 4,30; bl _s802D2B60_1; mr. 31,3; beq 2f; mr 4,28; mr 5,30; mr 3,31; crxor 6,6,6; bl _s802D2B60_2; stw 31,0x0(29); b 3f; 2:; mr 3,29; bl _s802D2B60_3; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802D2B60_0();
extern "C" void _s802D2B60_1();
extern "C" void _s802D2B60_2();
extern "C" void _s802D2B60_3();
extern "C" void f_802D2B60() {}
