// 0x80267578 __AIDHandler (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-13312; stw 0,0x4(1); addi 3,3,20480; li 0,-161; stwu 1,-736(1); stw 31,0x2dc(1); addi 31,4,0; lhz 5,0xa(3); and 0,5,0; ori 0,0,8; sth 0,0xa(3); addi 3,1,16; bl _s80267578_0; addi 3,1,16; bl _s80267578_1; lwz 3,-23132(13); cmplwi 3,0; beq 2f; lwz 0,-23116(13); cmpwi 0,0; bne 2f; lwz 0,-23128(13); li 4,1; stw 4,-23116(13); cmplwi 0,0; beq 0f; bl _s80267578_2; b 1f; 0:; addi 12,3,0; mtspr 8,12; blrl; 1:; li 0,0; stw 0,-23116(13); 2:; addi 3,1,16; bl _s80267578_3; mr 3,31; bl _s80267578_4; lwz 0,0x2e4(1); lwz 31,0x2dc(1); addi 1,1,736; mtspr 8,0"
extern "C" void _s80267578_0();
extern "C" void _s80267578_1();
extern "C" void _s80267578_2();
extern "C" void _s80267578_3();
extern "C" void _s80267578_4();
extern "C" void f_80267578() {}
