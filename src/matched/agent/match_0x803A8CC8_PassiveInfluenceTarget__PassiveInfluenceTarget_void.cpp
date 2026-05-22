// 0x803A8CC8 PassiveInfluenceTarget::PassiveInfluenceTarget(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); lis 9,-32698; mr 30,3; li 0,0; addi 9,9,8936; stw 9,0x0(30); addi 11,30,8; stw 0,0x8(30); addi 9,11,8; stw 0,0x4(11); addi 29,30,28; stw 0,0x4(9); li 3,16; stw 0,0x4(29); bl _s803A8CC8_0; mr 9,3; stw 9,0x0(9); mr 3,30; stw 9,0x4(9); stw 9,0x4(29); lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s803A8CC8_0();
extern "C" void f_803A8CC8() {}
