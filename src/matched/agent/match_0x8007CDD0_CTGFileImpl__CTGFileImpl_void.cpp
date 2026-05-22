// 0x8007CDD0 CTGFileImpl::CTGFileImpl(void (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 30,3; addi 9,9,-12888; addi 3,30,4; stw 9,0x0(30); addi 4,30,12; li 5,260; bl _s8007CDD0_0; li 0,0; mr 3,30; stw 0,0x110(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8007CDD0_0();
extern "C" void f_8007CDD0() {}
