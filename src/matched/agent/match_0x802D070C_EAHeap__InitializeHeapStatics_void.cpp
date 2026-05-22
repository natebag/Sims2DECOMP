// 0x802D070C EAHeap::InitializeHeapStatics(void) (384 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,-22840(13); lis 11,-32694; cmpwi 0,0; bne 1f; addi 9,11,6784; stw 0,0x1a80(11); stw 0,0x4(9); addi 31,9,8; li 30,7; 0:; mr 3,31; li 4,0; li 5,0; li 6,0; li 7,0; addi 31,31,52; bl _s802D070C_0; cmpwi 30,0; addi 30,30,-1; bne 0b; li 0,1; lis 3,-32723; stw 0,-22840(13); addi 3,3,1696; bl _s802D070C_1; 1:; lis 9,-32694; lis 4,-32702; addi 9,9,6784; addi 4,4,-6952; mr 3,9; stw 9,-21324(13); bl _s802D070C_2; lis 30,-32718; bl _s802D070C_3; li 4,6; li 5,0; bl _s802D070C_4; bl _s802D070C_5; li 4,6; li 5,0; bl _s802D070C_6; bl _s802D070C_7; addi 4,30,30468; li 5,0; bl _s802D070C_8; bl _s802D070C_9; addi 4,30,30468; li 5,0; bl _s802D070C_10; bl _s802D070C_11; addi 4,30,30468; li 5,0; bl _s802D070C_12; bl _s802D070C_13; lis 4,-32718; li 5,0; addi 4,4,30568; bl _s802D070C_14; bl _s802D070C_15; lis 4,-32718; li 5,0; addi 4,4,30660; bl _s802D070C_16; bl _s802D070C_17; lis 4,-32718; li 5,0; addi 4,4,30964; bl _s802D070C_18; bl _s802D070C_19; lis 4,-32718; li 5,0; addi 4,4,31004; bl _s802D070C_20; bl _s802D070C_21; lis 4,-32718; li 5,0; addi 4,4,31088; bl _s802D070C_22; bl _s802D070C_23; lis 4,-32718; li 5,0; addi 4,4,31128; bl _s802D070C_24; bl _s802D070C_25; lis 4,-32718; li 5,0; addi 4,4,31212; bl _s802D070C_26; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D070C_0();
extern "C" void _s802D070C_1();
extern "C" void _s802D070C_2();
extern "C" void _s802D070C_3();
extern "C" void _s802D070C_4();
extern "C" void _s802D070C_5();
extern "C" void _s802D070C_6();
extern "C" void _s802D070C_7();
extern "C" void _s802D070C_8();
extern "C" void _s802D070C_9();
extern "C" void _s802D070C_10();
extern "C" void _s802D070C_11();
extern "C" void _s802D070C_12();
extern "C" void _s802D070C_13();
extern "C" void _s802D070C_14();
extern "C" void _s802D070C_15();
extern "C" void _s802D070C_16();
extern "C" void _s802D070C_17();
extern "C" void _s802D070C_18();
extern "C" void _s802D070C_19();
extern "C" void _s802D070C_20();
extern "C" void _s802D070C_21();
extern "C" void _s802D070C_22();
extern "C" void _s802D070C_23();
extern "C" void _s802D070C_24();
extern "C" void _s802D070C_25();
extern "C" void _s802D070C_26();
extern "C" void f_802D070C() {}
