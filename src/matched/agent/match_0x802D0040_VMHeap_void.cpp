// 0x802D0040 VMHeap(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-22880(13); cmpwi 0,0; bne 0f; bl _s802D0040_0; mr 7,3; lis 4,-32702; lis 3,-32694; li 5,0; li 6,0; li 8,0; addi 4,4,-7096; addi 3,3,-6576; bl _s802D0040_1; li 0,1; lis 3,-32723; stw 0,-22880(13); addi 3,3,20; bl _s802D0040_2; 0:; lis 9,-32694; addi 9,9,-6576; mr 3,9; stw 9,-22820(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802D0040_0();
extern "C" void _s802D0040_1();
extern "C" void _s802D0040_2();
extern "C" void f_802D0040() {}
