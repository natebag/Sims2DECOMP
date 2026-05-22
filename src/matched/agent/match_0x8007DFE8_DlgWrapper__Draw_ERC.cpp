// 0x8007DFE8 DlgWrapper::Draw(ERC (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 0,0xb4(31); cmpwi 0,0; beq 0f; lis 4,-32707; addi 4,4,27032; bl _s8007DFE8_0; mr 4,29; mr 3,31; bl _s8007DFE8_1; lis 4,-32707; mr 3,31; addi 4,4,27052; bl _s8007DFE8_2; b 1f; 0:; lwz 30,0xa0(31); lis 4,-32707; stw 0,0xa0(31); addi 4,4,27032; mr 3,31; bl _s8007DFE8_3; mr 4,29; mr 3,31; bl _s8007DFE8_4; lis 4,-32707; mr 3,31; addi 4,4,27052; bl _s8007DFE8_5; stw 30,0xa0(31); 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8007DFE8_0();
extern "C" void _s8007DFE8_1();
extern "C" void _s8007DFE8_2();
extern "C" void _s8007DFE8_3();
extern "C" void _s8007DFE8_4();
extern "C" void _s8007DFE8_5();
extern "C" void f_8007DFE8() {}
