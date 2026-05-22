// 0x80287650 AptArray::sMethod_sort(AptValue (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x0(3); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,22; bne 0f; rlwinm 11,9,5,31,31; 0:; cmpwi 11,0; beq 2f; cmpwi 4,0; bne 1f; lwz 4,0x2c(3); lis 6,-32728; lwz 3,0x24(3); addi 6,6,29712; li 5,4; bl _s80287650_0; b 2f; 1:; lis 9,-32694; lwz 4,0x2c(3); lwz 11,-16032(9); lis 6,-32728; addi 9,9,-16032; lwz 3,0x24(3); lwz 0,0x8(9); rlwinm 11,11,2,0,29; addi 6,6,29920; li 5,4; add 11,11,0; lwz 9,-4(11); lwz 0,0x24(9); stw 9,-27540(13); stw 0,-27536(13); bl _s80287650_1; 2:; lwz 3,-22936(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80287650_0();
extern "C" void _s80287650_1();
extern "C" void f_80287650() {}
