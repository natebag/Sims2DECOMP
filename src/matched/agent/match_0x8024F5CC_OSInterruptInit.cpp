// 0x8024F5CC __OSInterruptInit (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); lis 31,-32768; addi 0,31,12352; stw 0,-23664(13); li 4,0; li 5,128; lwz 3,-23664(13); bl _s8024F5CC_0; li 0,0; stw 0,0xc4(31); lis 3,-13312; addi 4,3,12288; stw 0,0xc8(31); li 0,240; li 3,-32; stw 0,0x4(4); bl _s8024F5CC_1; lis 3,-32731; addi 4,3,-504; li 3,4; bl _s8024F5CC_2; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8024F5CC_0();
extern "C" void _s8024F5CC_1();
extern "C" void _s8024F5CC_2();
extern "C" void f_8024F5CC() {}
