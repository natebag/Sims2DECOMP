// 0x80159A2C ObjectDataBehaviorConstants::ObjectDataBehaviorConstants(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 30,3; li 0,0; addi 9,9,22352; sth 0,0x4(30); addi 3,30,8; stw 9,0x0(30); li 4,-1; li 5,0; bl _s80159A2C_0; li 0,0; mr 3,30; stw 0,0x14(30); stw 0,0x10(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80159A2C_0();
extern "C" void f_80159A2C() {}
