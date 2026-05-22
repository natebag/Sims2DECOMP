// 0x8016232C CasNpcEditor::CasNpcEditor(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; li 29,0; lis 9,-32698; stw 29,0x0(30); addi 9,9,24520; addi 3,30,92; stw 9,0x4(30); bl _s8016232C_0; addi 3,30,96; bl _s8016232C_1; addi 3,30,100; bl _s8016232C_2; lis 9,-32706; stw 29,0x58(30); lfs f0,-2660(9); mr 3,30; stw 29,0x8(30); stfs f0,0x14(30); stw 29,0xc(30); stw 29,0x10(30); stb 29,0x18(30); stb 29,0x38(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8016232C_0();
extern "C" void _s8016232C_1();
extern "C" void _s8016232C_2();
extern "C" void f_8016232C() {}
