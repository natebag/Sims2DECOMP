// 0x8024D128 L2Init (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); bl _s8024D128_0; mr 31,3; sync; li 3,48; bl _s8024D128_1; sync; bl _s8024D128_2; bl _s8024D128_3; mr 3,31; bl _s8024D128_4; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8024D128_0();
extern "C" void _s8024D128_1();
extern "C" void _s8024D128_2();
extern "C" void _s8024D128_3();
extern "C" void _s8024D128_4();
extern "C" void f_8024D128() {}
