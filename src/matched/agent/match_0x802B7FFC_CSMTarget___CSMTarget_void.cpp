// 0x802B7FFC CSMTarget::~CSMTarget(void) (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,5; mr 30,3; mr 5,4; li 4,43; li 7,1; bl _s802B7FFC_0; lis 9,-32703; stw 29,0x34(30); addi 9,9,27800; mr 3,30; stw 9,0x8(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 6,5; li 4,43; mr 5,29; bl _s802B7FFC_1; lis 9,-32703; mr 3,30; addi 9,9,27800; stw 9,0x8(30); lwz 0,0x34(29); stw 0,0x34(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,5; mr 30,3; mr 5,4; li 4,44; li 7,1; bl _s802B7FFC_2; lis 9,-32703; stw 29,0x34(30); addi 9,9,27584; mr 3,30; stw 9,0x8(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 6,5; li 4,44; mr 5,29; bl _s802B7FFC_3; lis 9,-32703; mr 3,30; addi 9,9,27584; stw 9,0x8(30); lwz 0,0x34(29); stw 0,0x34(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32703; mr 31,3; mr 30,4; addi 9,9,27800; stw 9,0x8(31); li 4,0; bl _s802B7FFC_4; andi. 0,30,1; beq 0f; lwz 3,-23016(13); mr 4,31; li 5,56; bl _s802B7FFC_5; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802B7FFC_0();
extern "C" void _s802B7FFC_1();
extern "C" void _s802B7FFC_2();
extern "C" void _s802B7FFC_3();
extern "C" void _s802B7FFC_4();
extern "C" void _s802B7FFC_5();
extern "C" void f_802B7FFC() {}
