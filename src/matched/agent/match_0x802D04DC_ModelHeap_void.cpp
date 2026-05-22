// 0x802D04DC ModelHeap(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,-22852(13); cmpwi 0,0; bne 0f; bl _s802D04DC_0; mr 30,3; bl _s802D04DC_1; mr 8,3; lis 4,-32702; lis 3,-32694; mr 7,30; li 5,0; li 6,0; addi 4,4,-7016; addi 3,3,2776; bl _s802D04DC_2; li 0,1; lis 3,-32723; stw 0,-22852(13); addi 3,3,1200; bl _s802D04DC_3; 0:; lis 9,-32694; addi 9,9,2776; mr 3,9; stw 9,-22792(13); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D04DC_0();
extern "C" void _s802D04DC_1();
extern "C" void _s802D04DC_2();
extern "C" void _s802D04DC_3();
extern "C" void f_802D04DC() {}
