// 0x802BC8B0 EAStringC::Append(char (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); li 31,0; mr 29,3; mr 28,4; cmplw 31,5; bge 1f; lbz 0,0x0(28); addi 9,28,1; cmpwi 0,0; beq 1f; 0:; addi 31,31,1; cmplw 31,5; bge 1f; lbz 0,0x0(9); addi 9,9,1; cmpwi 0,0; bne 0b; 1:; cmpwi 31,0; beq 2f; lwz 9,0x0(29); mr 3,29; li 5,0; li 7,1; lhz 30,0x2(9); add 4,30,31; mr 6,30; mr 8,4; bl _s802BC8B0_0; lwz 3,0x0(29); mr 4,28; mr 5,31; addi 3,3,8; add 3,3,30; crxor 6,6,6; bl _s802BC8B0_1; 2:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802BC8B0_0();
extern "C" void _s802BC8B0_1();
extern "C" void f_802BC8B0() {}
