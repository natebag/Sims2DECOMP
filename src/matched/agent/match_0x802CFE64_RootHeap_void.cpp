// 0x802CFE64 RootHeap(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-22892(13); cmpwi 0,0; bne 0f; lis 4,-32702; lis 3,-32694; addi 3,3,-10584; addi 4,4,-7136; li 5,0; li 6,0; li 7,0; li 8,0; bl _s802CFE64_0; li 0,1; lis 3,-32723; stw 0,-22892(13); addi 3,3,-456; bl _s802CFE64_1; 0:; lis 9,-32694; addi 9,9,-10584; mr 3,9; stw 9,-22832(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802CFE64_0();
extern "C" void _s802CFE64_1();
extern "C" void f_802CFE64() {}
