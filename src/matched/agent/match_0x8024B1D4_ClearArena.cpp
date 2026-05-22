// 0x8024B1D4 ClearArena (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); stw 30,0x8(1); bl _s8024B1D4_0; rlwinm 0,3,0,0,0; cmplwi 0,0; beq 0f; li 0,1; b 1f; 0:; li 0,0; 1:; cmpwi 0,0; bne 2f; bl _s8024B1D4_1; mr 30,3; bl _s8024B1D4_2; subf 30,3,30; bl _s8024B1D4_3; mr 5,30; li 4,0; bl _s8024B1D4_4; b 5f; 2:; lis 3,-32694; addi 30,3,-24816; addi 31,30,12; lwz 0,0x0(31); cmplwi 0,0; bne 3f; bl _s8024B1D4_5; mr 31,3; bl _s8024B1D4_6; subf 31,3,31; bl _s8024B1D4_7; mr 5,31; li 4,0; bl _s8024B1D4_8; b 5f; 3:; bl _s8024B1D4_9; lwz 0,0x0(31); cmplw 3,0; bge 5f; bl _s8024B1D4_10; lwz 0,0x0(31); cmplw 3,0; bgt 4f; bl _s8024B1D4_11; mr 31,3; bl _s8024B1D4_12; subf 31,3,31; bl _s8024B1D4_13; mr 5,31; li 4,0; bl _s8024B1D4_14; b 5f; 4:; bl _s8024B1D4_15; lwz 0,0x0(31); subf 31,3,0; bl _s8024B1D4_16; mr 5,31; li 4,0; bl _s8024B1D4_17; bl _s8024B1D4_18; addi 4,30,16; lwz 30,0x0(4); cmplw 3,30; ble 5f; bl _s8024B1D4_19; subf 5,30,3; mr 3,30; li 4,0; bl _s8024B1D4_20; 5:; lwz 0,0x14(1); lwz 31,0xc(1); lwz 30,0x8(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8024B1D4_0();
extern "C" void _s8024B1D4_1();
extern "C" void _s8024B1D4_2();
extern "C" void _s8024B1D4_3();
extern "C" void _s8024B1D4_4();
extern "C" void _s8024B1D4_5();
extern "C" void _s8024B1D4_6();
extern "C" void _s8024B1D4_7();
extern "C" void _s8024B1D4_8();
extern "C" void _s8024B1D4_9();
extern "C" void _s8024B1D4_10();
extern "C" void _s8024B1D4_11();
extern "C" void _s8024B1D4_12();
extern "C" void _s8024B1D4_13();
extern "C" void _s8024B1D4_14();
extern "C" void _s8024B1D4_15();
extern "C" void _s8024B1D4_16();
extern "C" void _s8024B1D4_17();
extern "C" void _s8024B1D4_18();
extern "C" void _s8024B1D4_19();
extern "C" void _s8024B1D4_20();
extern "C" void f_8024B1D4() {}
