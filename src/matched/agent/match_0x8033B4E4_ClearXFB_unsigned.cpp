// 0x8033B4E4 ClearXFB(unsigned (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="add 9,3,4; cmplw 3,9; bgelr; lis 0,4224; ori 0,0,4224; 0:; stw 0,0x0(3); addi 3,3,4; cmplw 3,9; blt 0b"
extern "C" void f_8033B4E4() {}
