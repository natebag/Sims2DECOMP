// 0x8035CA0C ENCamera::ENCamera(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 30,3; addi 9,9,-10168; addi 3,30,72; stw 9,0x54(30); bl _s8035CA0C_0; li 9,0; li 0,0; stb 0,0x0(30); mr 3,30; stw 9,0x44(30); stw 9,0x40(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8035CA0C_0();
extern "C" void f_8035CA0C() {}
