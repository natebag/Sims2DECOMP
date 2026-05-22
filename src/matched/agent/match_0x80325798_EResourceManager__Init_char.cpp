// 0x80325798 EResourceManager::Init(char (832 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; stw 4,0x40(31); bl _s80325798_0; lwz 11,-22652(13); mr 4,31; lwz 9,0x0(11); lha 3,0x40(9); lwz 0,0x44(9); add 3,11,3; mtspr 8,0; blrl; stw 3,0x4c(31); lis 3,-32702; lwz 4,0x40(31); addi 3,3,3796; bl _s80325798_1; cmpwi 3,0; beq 0f; lis 3,-32702; lwz 4,0x40(31); addi 3,3,3804; bl _s80325798_2; cmpwi 3,0; bne 1f; 0:; lwz 5,0x40(31); addi 3,31,3336; li 4,800; bl _s80325798_3; b 16f; 1:; lis 3,-32702; lwz 4,0x40(31); addi 3,3,3816; bl _s80325798_4; cmpwi 3,0; beq 8f; lis 3,-32702; lwz 4,0x40(31); addi 3,3,3828; bl _s80325798_5; cmpwi 3,0; beq 10f; lis 3,-32702; lwz 4,0x40(31); addi 3,3,3836; bl _s80325798_6; cmpwi 3,0; beq 2f; lis 3,-32702; lwz 4,0x40(31); addi 3,3,3844; bl _s80325798_7; cmpwi 3,0; bne 3f; 2:; lwz 5,0x40(31); addi 3,31,3336; li 4,150; bl _s80325798_8; b 16f; 3:; lis 3,-32702; lwz 4,0x40(31); addi 3,3,3856; bl _s80325798_9; cmpwi 3,0; bne 4f; lwz 5,0x40(31); addi 3,31,3336; li 4,100; bl _s80325798_10; b 16f; 4:; lis 3,-32702; lwz 4,0x40(31); addi 3,3,3868; bl _s80325798_11; cmpwi 3,0; bne 5f; lwz 5,0x40(31); addi 3,31,3336; li 4,20; bl _s80325798_12; b 16f; 5:; lis 3,-32702; lwz 4,0x40(31); addi 3,3,3880; bl _s80325798_13; cmpwi 3,0; bne 6f; lwz 5,0x40(31); addi 3,31,3336; li 4,50; bl _s80325798_14; b 16f; 6:; lis 3,-32702; lwz 4,0x40(31); addi 3,3,3888; bl _s80325798_15; cmpwi 3,0; bne 7f; lwz 5,0x40(31); addi 3,31,3336; li 4,700; bl _s80325798_16; b 16f; 7:; lis 3,-32702; lwz 4,0x40(31); addi 3,3,3900; bl _s80325798_17; cmpwi 3,0; bne 9f; 8:; lwz 5,0x40(31); addi 3,31,3336; li 4,500; bl _s80325798_18; b 16f; 9:; lis 3,-32702; lwz 4,0x40(31); addi 3,3,3920; bl _s80325798_19; cmpwi 3,0; bne 11f; 10:; lwz 5,0x40(31); addi 3,31,3336; li 4,250; bl _s80325798_20; b 16f; 11:; lis 3,-32702; lwz 4,0x40(31); addi 3,3,3936; bl _s80325798_21; cmpwi 3,0; beq 14f; lis 3,-32702; lwz 4,0x40(31); addi 3,3,3956; bl _s80325798_22; cmpwi 3,0; beq 14f; lis 3,-32702; lwz 4,0x40(31); addi 3,3,3964; bl _s80325798_23; cmpwi 3,0; bne 12f; lwz 5,0x40(31); addi 3,31,3336; li 4,550; bl _s80325798_24; b 16f; 12:; lis 3,-32702; lwz 4,0x40(31); addi 3,3,3980; bl _s80325798_25; cmpwi 3,0; beq 14f; lis 3,-32702; lwz 4,0x40(31); addi 3,3,3996; bl _s80325798_26; cmpwi 3,0; beq 14f; lis 3,-32702; lwz 4,0x40(31); addi 3,3,4004; bl _s80325798_27; cmpwi 3,0; bne 13f; lwz 5,0x40(31); addi 3,31,3336; li 4,10; bl _s80325798_28; b 16f; 13:; lis 3,-32702; lwz 4,0x40(31); addi 3,3,4016; bl _s80325798_29; cmpwi 3,0; beq 14f; lis 3,-32702; lwz 4,0x40(31); addi 3,3,4032; bl _s80325798_30; cmpwi 3,0; beq 14f; lis 3,-32702; lwz 4,0x40(31); addi 3,3,4048; bl _s80325798_31; cmpwi 3,0; bne 15f; 14:; lwz 5,0x40(31); addi 3,31,3336; li 4,4; bl _s80325798_32; b 16f; 15:; lwz 5,0x40(31); addi 3,31,3336; li 4,16; bl _s80325798_33; 16:; li 0,1; stw 0,0x48(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80325798_0();
extern "C" void _s80325798_1();
extern "C" void _s80325798_2();
extern "C" void _s80325798_3();
extern "C" void _s80325798_4();
extern "C" void _s80325798_5();
extern "C" void _s80325798_6();
extern "C" void _s80325798_7();
extern "C" void _s80325798_8();
extern "C" void _s80325798_9();
extern "C" void _s80325798_10();
extern "C" void _s80325798_11();
extern "C" void _s80325798_12();
extern "C" void _s80325798_13();
extern "C" void _s80325798_14();
extern "C" void _s80325798_15();
extern "C" void _s80325798_16();
extern "C" void _s80325798_17();
extern "C" void _s80325798_18();
extern "C" void _s80325798_19();
extern "C" void _s80325798_20();
extern "C" void _s80325798_21();
extern "C" void _s80325798_22();
extern "C" void _s80325798_23();
extern "C" void _s80325798_24();
extern "C" void _s80325798_25();
extern "C" void _s80325798_26();
extern "C" void _s80325798_27();
extern "C" void _s80325798_28();
extern "C" void _s80325798_29();
extern "C" void _s80325798_30();
extern "C" void _s80325798_31();
extern "C" void _s80325798_32();
extern "C" void _s80325798_33();
extern "C" void f_80325798() {}
