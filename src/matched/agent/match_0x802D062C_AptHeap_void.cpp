// 0x802D062C AptHeap(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-22844(13); cmpwi 0,0; bne 0f; bl _s802D062C_0; mr 7,3; lis 4,-32702; lis 3,-32694; li 5,0; li 6,0; li 8,0; addi 4,4,-6992; addi 3,3,5448; bl _s802D062C_1; li 0,1; lis 3,-32723; stw 0,-22844(13); addi 3,3,1536; bl _s802D062C_2; 0:; lis 9,-32694; addi 9,9,5448; mr 3,9; stw 9,-22784(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802D062C_0();
extern "C" void _s802D062C_1();
extern "C" void _s802D062C_2();
extern "C" void f_802D062C() {}
