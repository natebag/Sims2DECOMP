// 0x80350750 ENgcTextureC4_32::ENgcTextureC4_32(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,8; li 5,8; li 6,8; bl _s80350750_0; lis 9,-32697; li 0,0; addi 9,9,-11880; stw 0,0xd0(30); stw 9,0x24(30); mr 3,30; stw 0,0xcc(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80350750_0();
extern "C" void f_80350750() {}
