// 0x8016FC44 CasSimRendererDynamic::SetupSim(void) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; addi 3,1,8; mr 31,3; bl _s8016FC44_0; lwz 9,0x144(30); lwz 0,0x84(9); cmpwi 0,0; beq 0f; lis 4,-32706; mr 3,31; addi 4,4,6632; bl _s8016FC44_1; lis 9,-32702; addi 9,9,18064; b 1f; 0:; lis 4,-32706; mr 3,31; addi 4,4,6640; bl _s8016FC44_2; lis 9,-32702; addi 9,9,17920; 1:; stw 9,0x224(30); lwz 9,0x224(30); lis 11,-32706; lfs f1,0x19f8(11); addi 30,30,372; lwz 5,0x0(9); li 4,1; li 6,-1; li 7,0; mr 3,30; bl _s8016FC44_3; mr 3,30; li 4,1; bl _s8016FC44_4; lwz 4,0x8(1); mr 3,31; bl _s8016FC44_5; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8016FC44_0();
extern "C" void _s8016FC44_1();
extern "C" void _s8016FC44_2();
extern "C" void _s8016FC44_3();
extern "C" void _s8016FC44_4();
extern "C" void _s8016FC44_5();
extern "C" void f_8016FC44() {}
