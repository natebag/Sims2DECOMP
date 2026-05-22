// 0x800971C8 TheSimsEAMovieState::Startup(void) (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s800971C8_0; bl _s800971C8_1; bl _s800971C8_2; bl _s800971C8_3; bl _s800971C8_4; bl _s800971C8_5; bl _s800971C8_6; bl _s800971C8_7; bl _s800971C8_8; bl _s800971C8_9; bl _s800971C8_10; bl _s800971C8_11; bl _s800971C8_12; bl _s800971C8_13; bl _s800971C8_14; bl _s800971C8_15; bl _s800971C8_16; bl _s800971C8_17; bl _s800971C8_18; bl _s800971C8_19; bl _s800971C8_20; bl _s800971C8_21; bl _s800971C8_22; bl _s800971C8_23; bl _s800971C8_24; bl _s800971C8_25; bl _s800971C8_26; lwz 10,-26564(13); lis 9,-32706; lwz 11,0x0(10); lfs f1,-29812(9); lha 3,0x60(11); lwz 0,0x64(11); add 3,10,3; mtspr 8,0; blrl; lis 9,-32697; lwz 9,0x6208(9); cmpwi 9,0; beq 0f; lis 9,-32706; mr 3,31; lfs f1,-29808(9); li 4,3; bl _s800971C8_27; b 1f; 0:; stw 9,-28408(13); li 0,1; stw 9,-28404(13); lis 3,-32697; stw 0,0x1c(31); addi 3,3,23428; bl _s800971C8_28; mr 4,3; li 5,-1; lis 3,-32697; li 6,-1; addi 3,3,-7672; bl _s800971C8_29; 1:; lis 3,-32697; addi 3,3,23428; bl _s800971C8_30; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800971C8_0();
extern "C" void _s800971C8_1();
extern "C" void _s800971C8_2();
extern "C" void _s800971C8_3();
extern "C" void _s800971C8_4();
extern "C" void _s800971C8_5();
extern "C" void _s800971C8_6();
extern "C" void _s800971C8_7();
extern "C" void _s800971C8_8();
extern "C" void _s800971C8_9();
extern "C" void _s800971C8_10();
extern "C" void _s800971C8_11();
extern "C" void _s800971C8_12();
extern "C" void _s800971C8_13();
extern "C" void _s800971C8_14();
extern "C" void _s800971C8_15();
extern "C" void _s800971C8_16();
extern "C" void _s800971C8_17();
extern "C" void _s800971C8_18();
extern "C" void _s800971C8_19();
extern "C" void _s800971C8_20();
extern "C" void _s800971C8_21();
extern "C" void _s800971C8_22();
extern "C" void _s800971C8_23();
extern "C" void _s800971C8_24();
extern "C" void _s800971C8_25();
extern "C" void _s800971C8_26();
extern "C" void _s800971C8_27();
extern "C" void _s800971C8_28();
extern "C" void _s800971C8_29();
extern "C" void _s800971C8_30();
extern "C" void f_800971C8() {}
