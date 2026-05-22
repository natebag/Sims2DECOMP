// 0x80203784 SetVar_EYE_state::SetVar_EYE_state(char (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 30,3; addi 9,9,32728; mr 3,4; stw 9,0x8(30); stw 4,0x0(30); bl _s80203784_0; lis 9,-32698; stw 3,0x4(30); addi 9,9,32696; mr 3,30; stw 9,0x8(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80203784_0();
extern "C" void f_80203784() {}
