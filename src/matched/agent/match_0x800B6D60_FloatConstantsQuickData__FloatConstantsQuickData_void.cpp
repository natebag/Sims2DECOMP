// 0x800B6D60 FloatConstantsQuickData::FloatConstantsQuickData(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 30,3; addi 9,9,-4304; addi 3,30,4; stw 9,0x0(30); li 4,-1; li 5,0; bl _s800B6D60_0; li 0,0; mr 3,30; stw 0,0x10(30); stw 0,0xc(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800B6D60_0();
extern "C" void f_800B6D60() {}
