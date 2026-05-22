// 0x8016FBA0 CasSimRendererDynamic::CasSimRendererDynamic(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8016FBA0_0; lis 8,-32702; lis 9,-32698; addi 9,9,24944; addi 11,8,17920; stw 9,0x4(30); li 0,0; stw 11,0x224(30); li 10,1; mr 3,30; lwz 9,0x4600(8); stw 10,0x220(30); stw 9,0x218(30); stw 0,0x214(30); stw 0,0x21c(30); stw 0,0x228(30); stw 0,0x22c(30); stw 0,0x230(30); stw 0,0x234(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8016FBA0_0();
extern "C" void f_8016FBA0() {}
