// 0x8032B7A8 ENgcAudio::ENgcAudio(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 30,3; addi 9,9,-16304; addi 3,30,64; stw 9,0x0(30); bl _s8032B7A8_0; addi 3,30,92; bl _s8032B7A8_1; lis 9,-32702; lis 11,-32702; lfs f13,0x14d4(9); li 0,0; lfs f0,0x14d8(11); mr 3,30; stfs f13,0x4(30); stfs f0,0x8(30); stw 30,-26564(13); stw 0,0x3c(30); stw 0,0x38(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8032B7A8_0();
extern "C" void _s8032B7A8_1();
extern "C" void f_8032B7A8() {}
