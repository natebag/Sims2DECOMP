// 0x801A0514 CASRoommateTarget::SetButtonState(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 0,0x1c(1); addi 4,1,8; bl _s801A0514_0; addi 0,1,8; lis 3,-32705; stw 0,0x10(1); addi 3,3,-11380; li 4,0; li 5,0; li 6,1; addi 7,1,16; bl _s801A0514_1; lwz 0,0x1c(1); mtspr 8,0; addi 1,1,24"
extern "C" void _s801A0514_0();
extern "C" void _s801A0514_1();
extern "C" void f_801A0514() {}
