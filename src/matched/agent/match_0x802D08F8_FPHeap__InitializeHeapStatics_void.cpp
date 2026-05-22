// 0x802D08F8 FPHeap::InitializeHeapStatics(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,-22836(13); lis 11,-32694; cmpwi 0,0; bne 1f; addi 9,11,7208; stw 0,0x1c28(11); stw 0,0x4(9); addi 30,9,8; li 31,7; 0:; mr 3,30; li 4,0; li 5,0; li 6,0; li 7,0; addi 30,30,24; bl _s802D08F8_0; cmpwi 31,0; addi 31,31,-1; bne 0b; li 0,1; lis 3,-32723; stw 0,-22836(13); addi 3,3,2188; bl _s802D08F8_1; 1:; lis 9,-32694; lis 4,-32702; addi 9,9,7208; addi 4,4,-6984; mr 3,9; stw 9,-21320(13); bl _s802D08F8_2; bl _s802D08F8_3; lis 4,-32718; li 5,0; addi 4,4,31252; bl _s802D08F8_4; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D08F8_0();
extern "C" void _s802D08F8_1();
extern "C" void _s802D08F8_2();
extern "C" void _s802D08F8_3();
extern "C" void _s802D08F8_4();
extern "C" void f_802D08F8() {}
