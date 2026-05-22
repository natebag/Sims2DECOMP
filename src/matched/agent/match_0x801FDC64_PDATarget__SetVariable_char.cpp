// 0x801FDC64 PDATarget::SetVariable(char (512 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lis 3,-32704; mr 29,5; addi 3,3,-20592; bl _s801FDC64_0; cmpwi 3,0; bne 0f; mr 3,29; bl _s801FDC64_1; mr 4,3; lis 3,-32704; stw 4,0x14c(30); addi 3,3,-20052; bl _s801FDC64_2; b 10f; 0:; lis 3,-32704; mr 4,31; addi 3,3,-20528; bl _s801FDC64_3; cmpwi 3,0; bne 1f; mr 3,29; bl _s801FDC64_4; mr 4,3; lis 3,-32704; stw 4,0x150(30); addi 3,3,-20040; bl _s801FDC64_5; b 10f; 1:; lis 3,-32704; mr 4,31; addi 3,3,-20580; bl _s801FDC64_6; cmpwi 3,0; bne 2f; mr 3,29; bl _s801FDC64_7; stw 3,0x154(30); b 10f; 2:; lis 3,-32704; mr 4,31; addi 3,3,-20516; bl _s801FDC64_8; cmpwi 3,0; bne 3f; mr 3,29; bl _s801FDC64_9; stw 3,0x158(30); b 10f; 3:; lis 3,-32704; mr 4,31; addi 3,3,-20560; bl _s801FDC64_10; mr. 28,3; bne 5f; mr 3,30; li 4,0; bl _s801FDC64_11; cmpwi 3,0; beq 4f; li 0,1; stw 28,0x174(30); stw 0,0x170(30); b 10f; 4:; lis 3,-32704; addi 3,3,-20028; bl _s801FDC64_12; mr 5,3; li 4,0; b 7f; 5:; lis 3,-32704; mr 4,31; addi 3,3,-20496; bl _s801FDC64_13; cmpwi 3,0; bne 8f; mr 3,30; li 4,1; bl _s801FDC64_14; cmpwi 3,0; beq 6f; li 0,1; stw 0,0x174(30); stw 0,0x170(30); b 10f; 6:; lis 3,-32704; addi 3,3,-20012; bl _s801FDC64_15; mr 5,3; li 4,1; 7:; mr 3,30; bl _s801FDC64_16; b 10f; 8:; lis 3,-32704; mr 4,31; addi 3,3,-20548; bl _s801FDC64_17; cmpwi 3,0; bne 9f; mr 3,29; bl _s801FDC64_18; mr 5,3; li 4,0; mr 3,30; bl _s801FDC64_19; b 10f; 9:; lis 3,-32704; mr 4,31; addi 3,3,-20484; bl _s801FDC64_20; cmpwi 3,0; bne 10f; mr 3,29; bl _s801FDC64_21; mr 5,3; li 4,1; mr 3,30; bl _s801FDC64_22; 10:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801FDC64_0();
extern "C" void _s801FDC64_1();
extern "C" void _s801FDC64_2();
extern "C" void _s801FDC64_3();
extern "C" void _s801FDC64_4();
extern "C" void _s801FDC64_5();
extern "C" void _s801FDC64_6();
extern "C" void _s801FDC64_7();
extern "C" void _s801FDC64_8();
extern "C" void _s801FDC64_9();
extern "C" void _s801FDC64_10();
extern "C" void _s801FDC64_11();
extern "C" void _s801FDC64_12();
extern "C" void _s801FDC64_13();
extern "C" void _s801FDC64_14();
extern "C" void _s801FDC64_15();
extern "C" void _s801FDC64_16();
extern "C" void _s801FDC64_17();
extern "C" void _s801FDC64_18();
extern "C" void _s801FDC64_19();
extern "C" void _s801FDC64_20();
extern "C" void _s801FDC64_21();
extern "C" void _s801FDC64_22();
extern "C" void f_801FDC64() {}
