// 0x800C2D1C MotiveConstantsClient::MotiveConstantsClient(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,1; bl _s800C2D1C_0; lis 9,-32698; mr 3,30; addi 9,9,-2240; stw 9,0x0(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800C2D1C_0();
extern "C" void f_800C2D1C() {}
