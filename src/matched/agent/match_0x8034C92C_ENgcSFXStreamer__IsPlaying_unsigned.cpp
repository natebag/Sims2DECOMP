// 0x8034C92C ENgcSFXStreamer::IsPlaying(unsigned (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; li 31,1; bl _s8034C92C_0; mulli 30,30,68; lis 9,-32690; addi 9,9,-19244; add 30,30,9; lwz 0,0x40(30); cmpwi 0,0; blt 0f; li 31,0; 0:; bl _s8034C92C_1; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8034C92C_0();
extern "C" void _s8034C92C_1();
extern "C" void f_8034C92C() {}
