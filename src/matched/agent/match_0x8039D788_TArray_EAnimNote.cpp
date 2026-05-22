// 0x8039D788 TArray<EAnimNote, (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); addi 29,4,-1; mr 30,3; cmpwi 4,0; beq 1f; addi 31,3,-4; 0:; mr 9,30; addi 31,31,12; lwz 4,0x8(9); mr 3,31; addi 30,30,12; bl _s8039D788_0; cmpwi 29,0; addi 29,29,-1; bne 0b; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8039D788_0();
extern "C" void f_8039D788() {}
