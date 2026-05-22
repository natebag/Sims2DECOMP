// 0x8039D900 TArray<EAnimNote, (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); addi 28,5,-1; cmpwi 5,0; beq 1f; mr 30,3; mr 31,4; addi 29,3,-4; 0:; addi 31,31,12; addi 30,30,12; lwz 9,-12(31); addi 29,29,12; mr 3,29; stw 9,-12(30); lwz 0,-8(31); stw 0,-8(30); lwz 4,-4(31); bl _s8039D900_0; cmpwi 28,0; addi 28,28,-1; bne 0b; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8039D900_0();
extern "C" void f_8039D900() {}
