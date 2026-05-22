// 0x8024D448 __OSCacheInit (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); stw 30,0x8(1); lis 3,-32700; addi 31,3,-20544; bl _s8024D448_0; rlwinm 0,3,0,16,16; cmplwi 0,0; bne 0f; bl _s8024D448_1; addi 3,31,428; crxor 6,6,6; bl _s8024D448_2; 0:; bl _s8024D448_3; rlwinm 0,3,0,17,17; cmplwi 0,0; bne 1f; bl _s8024D448_4; addi 3,31,456; crxor 6,6,6; bl _s8024D448_5; 1:; bl _s8024D448_6; rlwinm 0,3,0,0,0; cmplwi 0,0; bne 2f; bl _s8024D448_7; mr 30,3; sync; li 3,48; bl _s8024D448_8; sync; sync; bl _s8024D448_9; rlwinm 3,3,0,1,31; bl _s8024D448_10; sync; bl _s8024D448_11; mr 3,30; bl _s8024D448_12; bl _s8024D448_13; oris 0,3,32768; rlwinm 3,0,0,11,9; bl _s8024D448_14; addi 3,31,484; crxor 6,6,6; bl _s8024D448_15; 2:; lis 3,-32731; addi 4,3,-11544; li 3,1; bl _s8024D448_16; addi 3,31,508; crxor 6,6,6; bl _s8024D448_17; lwz 0,0x14(1); lwz 31,0xc(1); lwz 30,0x8(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8024D448_0();
extern "C" void _s8024D448_1();
extern "C" void _s8024D448_2();
extern "C" void _s8024D448_3();
extern "C" void _s8024D448_4();
extern "C" void _s8024D448_5();
extern "C" void _s8024D448_6();
extern "C" void _s8024D448_7();
extern "C" void _s8024D448_8();
extern "C" void _s8024D448_9();
extern "C" void _s8024D448_10();
extern "C" void _s8024D448_11();
extern "C" void _s8024D448_12();
extern "C" void _s8024D448_13();
extern "C" void _s8024D448_14();
extern "C" void _s8024D448_15();
extern "C" void _s8024D448_16();
extern "C" void _s8024D448_17();
extern "C" void f_8024D448() {}
