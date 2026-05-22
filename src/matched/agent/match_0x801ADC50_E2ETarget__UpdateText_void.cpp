// 0x801ADC50 E2ETarget::UpdateText(void) (516 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 30,3; addi 3,1,8; bl _s801ADC50_0; addi 3,1,8; bl _s801ADC50_1; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-3420; bl _s801ADC50_2; lwz 4,0xa8(30); addi 3,1,8; subfic 0,4,0; adde 4,0,4; bl _s801ADC50_3; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-3404; bl _s801ADC50_4; lwz 4,0xa8(30); addi 3,1,8; xori 4,4,1; subfic 0,4,0; adde 4,0,4; bl _s801ADC50_5; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-3388; bl _s801ADC50_6; lwz 4,0xa8(30); addi 3,1,8; xori 4,4,2; subfic 0,4,0; adde 4,0,4; bl _s801ADC50_7; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-3372; bl _s801ADC50_8; lwz 4,0xa8(30); addi 3,1,8; xori 4,4,3; subfic 0,4,0; adde 4,0,4; bl _s801ADC50_9; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-3356; bl _s801ADC50_10; lwz 4,0xa8(30); addi 3,1,8; xori 4,4,4; subfic 0,4,0; adde 4,0,4; bl _s801ADC50_11; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-3340; bl _s801ADC50_12; lwz 4,0xa8(30); addi 3,1,8; xori 4,4,5; subfic 0,4,0; adde 4,0,4; bl _s801ADC50_13; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-3324; bl _s801ADC50_14; lwz 4,0xa8(30); addi 3,1,8; xori 4,4,6; subfic 0,4,0; adde 4,0,4; bl _s801ADC50_15; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-3308; bl _s801ADC50_16; lwz 4,0xa8(30); addi 3,1,8; xori 4,4,7; subfic 0,4,0; adde 4,0,4; bl _s801ADC50_17; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-3292; bl _s801ADC50_18; lwz 4,0xa8(30); addi 3,1,8; xori 4,4,8; subfic 0,4,0; adde 4,0,4; bl _s801ADC50_19; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-3276; bl _s801ADC50_20; lwz 4,0xa8(30); addi 3,1,8; xori 4,4,9; subfic 0,4,0; adde 4,0,4; bl _s801ADC50_21; addi 3,1,8; bl _s801ADC50_22; addi 3,1,8; li 4,2; bl _s801ADC50_23; li 3,0; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s801ADC50_0();
extern "C" void _s801ADC50_1();
extern "C" void _s801ADC50_2();
extern "C" void _s801ADC50_3();
extern "C" void _s801ADC50_4();
extern "C" void _s801ADC50_5();
extern "C" void _s801ADC50_6();
extern "C" void _s801ADC50_7();
extern "C" void _s801ADC50_8();
extern "C" void _s801ADC50_9();
extern "C" void _s801ADC50_10();
extern "C" void _s801ADC50_11();
extern "C" void _s801ADC50_12();
extern "C" void _s801ADC50_13();
extern "C" void _s801ADC50_14();
extern "C" void _s801ADC50_15();
extern "C" void _s801ADC50_16();
extern "C" void _s801ADC50_17();
extern "C" void _s801ADC50_18();
extern "C" void _s801ADC50_19();
extern "C" void _s801ADC50_20();
extern "C" void _s801ADC50_21();
extern "C" void _s801ADC50_22();
extern "C" void _s801ADC50_23();
extern "C" void f_801ADC50() {}
