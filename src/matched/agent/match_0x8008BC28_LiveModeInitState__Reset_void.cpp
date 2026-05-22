// 0x8008BC28 LiveModeInitState::Reset(void) (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,-24508(13); mr 31,3; cmpwi 9,0; beq 0f; addi 3,9,48; li 4,32; bl _s8008BC28_0; lwz 3,-24508(13); li 4,32; addi 3,3,48; bl _s8008BC28_1; 0:; lwz 3,-21492(13); li 4,3; bl _s8008BC28_2; lis 3,-32693; addi 3,3,6104; bl _s8008BC28_3; bl _s8008BC28_4; bl _s8008BC28_5; bl _s8008BC28_6; bl _s8008BC28_7; bl _s8008BC28_8; bl _s8008BC28_9; bl _s8008BC28_10; bl _s8008BC28_11; bl _s8008BC28_12; bl _s8008BC28_13; bl _s8008BC28_14; bl _s8008BC28_15; bl _s8008BC28_16; bl _s8008BC28_17; bl _s8008BC28_18; bl _s8008BC28_19; bl _s8008BC28_20; bl _s8008BC28_21; bl _s8008BC28_22; bl _s8008BC28_23; bl _s8008BC28_24; bl _s8008BC28_25; bl _s8008BC28_26; bl _s8008BC28_27; bl _s8008BC28_28; bl _s8008BC28_29; bl _s8008BC28_30; lis 9,-32697; lwz 11,0x5e80(9); li 0,1; li 9,0; lis 3,-32697; stw 0,0x3a8(11); addi 3,3,23428; stw 9,0xc(31); li 4,0; stw 9,0x1c(31); li 5,30; bl _s8008BC28_31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8008BC28_0();
extern "C" void _s8008BC28_1();
extern "C" void _s8008BC28_2();
extern "C" void _s8008BC28_3();
extern "C" void _s8008BC28_4();
extern "C" void _s8008BC28_5();
extern "C" void _s8008BC28_6();
extern "C" void _s8008BC28_7();
extern "C" void _s8008BC28_8();
extern "C" void _s8008BC28_9();
extern "C" void _s8008BC28_10();
extern "C" void _s8008BC28_11();
extern "C" void _s8008BC28_12();
extern "C" void _s8008BC28_13();
extern "C" void _s8008BC28_14();
extern "C" void _s8008BC28_15();
extern "C" void _s8008BC28_16();
extern "C" void _s8008BC28_17();
extern "C" void _s8008BC28_18();
extern "C" void _s8008BC28_19();
extern "C" void _s8008BC28_20();
extern "C" void _s8008BC28_21();
extern "C" void _s8008BC28_22();
extern "C" void _s8008BC28_23();
extern "C" void _s8008BC28_24();
extern "C" void _s8008BC28_25();
extern "C" void _s8008BC28_26();
extern "C" void _s8008BC28_27();
extern "C" void _s8008BC28_28();
extern "C" void _s8008BC28_29();
extern "C" void _s8008BC28_30();
extern "C" void _s8008BC28_31();
extern "C" void f_8008BC28() {}
