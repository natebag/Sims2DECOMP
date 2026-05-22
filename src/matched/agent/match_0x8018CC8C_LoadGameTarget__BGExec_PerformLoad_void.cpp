// 0x8018CC8C LoadGameTarget::BGExec_PerformLoad(void (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 3,3; beq 0f; bl _s8018CC8C_0; 0:; li 0,1; stw 0,-21480(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8018CC8C_0();
extern "C" void f_8018CC8C() {}
