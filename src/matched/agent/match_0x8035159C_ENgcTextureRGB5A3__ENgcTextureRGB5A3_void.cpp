// 0x8035159C ENgcTextureRGB5A3::ENgcTextureRGB5A3(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,5; li 5,4; li 6,4; bl _s8035159C_0; lis 9,-32697; mr 3,30; addi 9,9,-11112; stw 9,0x24(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8035159C_0();
extern "C" void f_8035159C() {}
