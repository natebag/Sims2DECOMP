// 0x801CF780 O2TTarget::SpawnQuitDialogBox(void) (736 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-2128(1); mfspr 0,8; stmw 28,0x840(1); stw 0,0x854(1); mr 31,3; li 28,0; li 0,3; stw 28,0xb0(31); stw 28,0xb8(31); lis 29,-32697; lis 5,-32705; addi 4,29,24012; stw 0,0xa4(31); addi 5,5,-1344; addi 3,1,2072; lis 30,-32697; crxor 6,6,6; bl _s801CF780_0; lwz 9,0x818(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; addi 3,1,8; bl _s801CF780_1; addi 4,1,8; addi 3,31,212; bl _s801CF780_2; lis 5,-32705; addi 4,30,24012; addi 3,1,2076; addi 5,5,-1340; crxor 6,6,6; bl _s801CF780_3; lwz 9,0x81c(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; addi 3,1,8; bl _s801CF780_4; addi 4,1,8; addi 3,31,216; bl _s801CF780_5; lis 5,-32705; addi 4,30,24012; addi 5,5,1784; addi 3,1,2080; crxor 6,6,6; bl _s801CF780_6; lwz 9,0x820(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; addi 3,1,8; bl _s801CF780_7; addi 4,1,8; addi 3,31,220; bl _s801CF780_8; lis 5,-32705; addi 4,29,24012; addi 5,5,8904; addi 3,1,2084; crxor 6,6,6; bl _s801CF780_9; lwz 9,0x824(1); li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; addi 3,1,8; bl _s801CF780_10; cmpwi 31,0; addi 4,1,8; mfcr 29; addi 3,31,204; bl _s801CF780_11; lis 4,-32705; addi 3,31,208; addi 4,4,-8284; bl _s801CF780_12; lis 9,-32705; stw 28,0xc4(31); addi 9,9,16112; lis 10,-32708; lwz 11,0x0(9); lwz 12,0x4(9); addi 4,1,2088; addi 30,10,-28660; stw 31,0x810(1); stw 11,0x828(1); stw 12,0x82c(1); mtcrf 128,29; beq 4f; addi 3,1,2056; li 5,8; bl _s801CF780_13; b 5f; 4:; stw 31,0x808(1); 5:; stw 30,0x814(1); lis 9,-32705; addi 11,1,2056; lwz 4,0x808(1); addi 9,9,16120; lwz 5,0x4(11); lwz 6,0x8(11); addi 10,31,244; lwz 0,0xc(11); mr 30,11; lwz 7,0x0(9); lwz 8,0x4(9); mtcrf 128,29; stw 4,0xf4(31); lis 9,-32708; stw 0,0xc(10); addi 28,9,-28540; stw 5,0x4(10); addi 9,1,2096; stw 6,0x8(10); stw 7,0x830(1); stw 8,0x834(1); stw 31,0x810(1); beq 6f; mr 4,9; mr 3,30; li 5,8; bl _s801CF780_14; b 7f; 6:; stw 31,0x808(1); 7:; stw 28,0x814(1); lis 9,-32705; lwz 5,0x808(1); addi 9,9,-1960; lwz 4,0x8(30); addi 11,31,260; lwz 6,0x4(30); addi 0,31,164; lwz 10,0xc(30); mr 29,0; lwz 7,0x0(9); lwz 8,0x4(9); cmpwi 0,0; stw 5,0x104(31); lis 9,-32709; stw 10,0xc(11); addi 28,9,14552; stw 6,0x4(11); addi 9,1,2104; stw 4,0x8(11); stw 7,0x838(1); stw 8,0x83c(1); stw 0,0x810(1); beq 8f; mr 4,9; mr 3,30; li 5,8; bl _s801CF780_15; b 9f; 8:; stw 29,0x808(1); 9:; stw 28,0x814(1); addi 9,31,276; lwz 8,0x808(1); mr 3,29; lwz 0,0xc(30); lwz 11,0x4(30); lwz 10,0x8(30); stw 8,0x114(31); stw 0,0xc(9); stw 11,0x4(9); stw 10,0x8(9); bl _s801CF780_16; lis 3,-32705; li 4,0; addi 3,3,15436; li 5,0; li 6,0; li 7,0; bl _s801CF780_17; lwz 0,0x854(1); mtspr 8,0; lmw 28,0x840(1); addi 1,1,2128"

extern "C" void _s801CF780_0();
extern "C" void _s801CF780_1();
extern "C" void _s801CF780_2();
extern "C" void _s801CF780_3();
extern "C" void _s801CF780_4();
extern "C" void _s801CF780_5();
extern "C" void _s801CF780_6();
extern "C" void _s801CF780_7();
extern "C" void _s801CF780_8();
extern "C" void _s801CF780_9();
extern "C" void _s801CF780_10();
extern "C" void _s801CF780_11();
extern "C" void _s801CF780_12();
extern "C" void _s801CF780_13();
extern "C" void _s801CF780_14();
extern "C" void _s801CF780_15();
extern "C" void _s801CF780_16();
extern "C" void _s801CF780_17();

struct O2TTarget {
    void SpawnQuitDialogBox();
};

void O2TTarget::SpawnQuitDialogBox() {
}
