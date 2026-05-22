// 0x800159A0 {anonymous}::IsUsingSpecifiedInteractor(int, (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; bl _s800159A0_0; mr 4,31; li 5,-1; bl _s800159A0_1; mr. 30,3; beq 0f; bl _s800159A0_2; mr 4,31; mr 5,29; bl _s800159A0_3; xor 3,30,3; subfic 0,3,0; adde 3,0,3; b 1f; 0:; li 3,0; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800159A0_0();
extern "C" void _s800159A0_1();
extern "C" void _s800159A0_2();
extern "C" void _s800159A0_3();
extern "C" void f_800159A0() {}
