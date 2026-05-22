// 0x802DFFDC EBitArray::Deinterleave(int, (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 22,0x20(1); stw 0,0x4c(1); mr 28,6; mr 29,5; mullw 23,29,28; mr 25,3; addi 3,1,8; mr 24,4; mr 22,3; mr 4,23; bl _s802DFFDC_0; li 4,0; cmpw 4,28; bge 3f; 0:; li 30,0; addi 26,4,1; cmpw 30,29; bge 2f; mullw 27,4,29; add 31,24,4; 1:; mr 4,31; mr 3,25; bl _s802DFFDC_1; add 31,31,28; mr 5,3; add 4,27,30; addi 3,1,8; addi 30,30,1; bl _s802DFFDC_2; cmpw 30,29; blt 1b; 2:; mr 4,26; cmpw 4,28; blt 0b; 3:; mr 3,25; mr 6,24; mr 7,23; addi 4,1,8; li 5,0; bl _s802DFFDC_3; lis 9,-32697; mr 3,22; addi 9,9,-23560; stw 9,0x10(22); bl _s802DFFDC_4; lwz 0,0x4c(1); mtspr 8,0; lmw 22,0x20(1); addi 1,1,72"
extern "C" void _s802DFFDC_0();
extern "C" void _s802DFFDC_1();
extern "C" void _s802DFFDC_2();
extern "C" void _s802DFFDC_3();
extern "C" void _s802DFFDC_4();
extern "C" void f_802DFFDC() {}
