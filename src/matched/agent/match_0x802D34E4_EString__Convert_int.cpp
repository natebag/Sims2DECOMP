// 0x802D34E4 EString::Convert(int) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 30,0x30(1); stw 0,0x3c(1); mr 5,4; mr 30,3; lis 4,-32702; addi 3,1,8; addi 4,4,-6892; crxor 6,6,6; bl _s802D34E4_0; mr 3,30; addi 4,1,8; bl _s802D34E4_1; mr 3,30; lwz 0,0x3c(1); mtspr 8,0; lmw 30,0x30(1); addi 1,1,56"
extern "C" void _s802D34E4_0();
extern "C" void _s802D34E4_1();
extern "C" void f_802D34E4() {}
