// 0x8016F050 CasSimRenderer::Init(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; addi 3,30,8; bl _s8016F050_0; li 10,0; lis 9,-32696; stw 10,0x170(30); addi 11,9,30808; addi 6,30,492; lis 4,-32696; lwz 8,0x7858(9); addi 3,4,30820; lwz 9,0x8(11); lis 7,-32706; lwz 0,0x4(11); addi 5,30,504; stw 8,0x1ec(30); stw 9,0x8(6); stw 0,0x4(6); lfs f0,0x1734(7); lwz 0,0x7864(4); lwz 9,0x8(3); lwz 11,0x4(3); stw 0,0x1f8(30); stw 9,0x8(5); stw 11,0x4(5); stw 10,0x210(30); stfs f0,0x20c(30); stw 10,0x204(30); stfs f0,0x208(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8016F050_0();
extern "C" void f_8016F050() {}
