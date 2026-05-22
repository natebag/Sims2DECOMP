// 0x8026B680 AptDebugGetCurrentFrame(int) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8026B680_0; mr. 3,3; beq 0f; lwz 3,0x4c(3); cmpwi 3,0; beq 0f; lwz 3,0x18(3); b 1f; 0:; li 3,-1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8026B680_0();
extern "C" void f_8026B680() {}
