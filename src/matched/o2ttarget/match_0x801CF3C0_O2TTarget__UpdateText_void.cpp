// 0x801CF3C0 O2TTarget::UpdateText(void) (836 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 22,0x20(1); stw 0,0x4c(1); mr 31,3; lis 29,-32705; addi 3,1,8; lis 27,-32705; bl _s801CF3C0_0; lis 30,-32705; addi 3,1,8; lis 25,-32705; bl _s801CF3C0_1; lis 28,-32705; addi 3,1,8; li 5,0; addi 4,29,15012; lis 24,-32705; bl _s801CF3C0_2; lis 26,-32705; lis 4,255; addi 3,1,8; ori 4,4,65535; lis 23,-32705; bl _s801CF3C0_3; lis 22,-32705; addi 3,1,8; li 5,0; addi 4,27,15032; bl _s801CF3C0_4; lis 4,255; addi 3,1,8; ori 4,4,65535; bl _s801CF3C0_5; addi 3,1,8; li 5,0; addi 4,30,15052; bl _s801CF3C0_6; lis 4,255; addi 3,1,8; ori 4,4,65535; bl _s801CF3C0_7; addi 3,1,8; li 5,0; addi 4,25,15072; bl _s801CF3C0_8; lis 4,255; addi 3,1,8; ori 4,4,65535; bl _s801CF3C0_9; addi 3,1,8; li 5,0; addi 4,28,15092; bl _s801CF3C0_10; lis 4,255; addi 3,1,8; ori 4,4,65535; bl _s801CF3C0_11; addi 3,1,8; li 5,0; addi 4,24,15116; bl _s801CF3C0_12; lis 4,255; addi 3,1,8; ori 4,4,65535; bl _s801CF3C0_13; addi 3,1,8; li 5,0; addi 4,26,15140; bl _s801CF3C0_14; lis 4,255; addi 3,1,8; ori 4,4,65535; bl _s801CF3C0_15; addi 3,1,8; li 5,0; addi 4,23,15164; bl _s801CF3C0_16; lis 4,255; addi 3,1,8; ori 4,4,65535; bl _s801CF3C0_17; addi 3,1,8; li 5,0; addi 4,22,15184; bl _s801CF3C0_18; lis 4,255; addi 3,1,8; ori 4,4,65535; bl _s801CF3C0_19; addi 3,1,8; bl _s801CF3C0_20; addi 3,1,8; bl _s801CF3C0_21; lwz 0,0x88(31); cmpwi 0,0; bne 1f; lwz 0,0x9c(31); cmpwi 0,0; bne 0f; addi 4,29,15012; addi 3,1,8; li 5,0; bl _s801CF3C0_22; li 4,0; addi 3,1,8; ori 4,4,65280; bl _s801CF3C0_23; 0:; lwz 0,0x9c(31); cmpwi 0,1; bne 8f; addi 4,27,15032; addi 3,1,8; li 5,0; bl _s801CF3C0_24; li 4,0; addi 3,1,8; ori 4,4,65280; bl _s801CF3C0_25; b 8f; 1:; cmpwi 0,2; bne 8f; lwz 0,0xa0(31); cmpwi 0,0; bne 2f; addi 4,30,15052; addi 3,1,8; li 5,0; bl _s801CF3C0_26; li 4,0; addi 3,1,8; ori 4,4,65280; bl _s801CF3C0_27; 2:; lwz 0,0xa0(31); cmpwi 0,1; bne 3f; addi 4,28,15092; addi 3,1,8; li 5,0; bl _s801CF3C0_28; li 4,0; addi 3,1,8; ori 4,4,65280; bl _s801CF3C0_29; 3:; lwz 0,0xa0(31); cmpwi 0,2; bne 4f; addi 4,26,15140; addi 3,1,8; li 5,0; bl _s801CF3C0_30; li 4,0; addi 3,1,8; ori 4,4,65280; bl _s801CF3C0_31; 4:; lwz 0,0xa0(31); cmpwi 0,3; bne 5f; addi 4,25,15072; addi 3,1,8; li 5,0; bl _s801CF3C0_32; li 4,0; addi 3,1,8; ori 4,4,65280; bl _s801CF3C0_33; 5:; lwz 0,0xa0(31); cmpwi 0,4; bne 6f; addi 4,24,15116; addi 3,1,8; li 5,0; bl _s801CF3C0_34; li 4,0; addi 3,1,8; ori 4,4,65280; bl _s801CF3C0_35; 6:; lwz 0,0xa0(31); cmpwi 0,5; bne 7f; addi 4,23,15164; addi 3,1,8; li 5,0; bl _s801CF3C0_36; li 4,0; addi 3,1,8; ori 4,4,65280; bl _s801CF3C0_37; 7:; lwz 0,0xa0(31); cmpwi 0,6; bne 8f; addi 4,22,15184; addi 3,1,8; li 5,0; bl _s801CF3C0_38; li 4,0; addi 3,1,8; ori 4,4,65280; bl _s801CF3C0_39; 8:; addi 3,1,8; bl _s801CF3C0_40; addi 3,1,8; li 4,2; bl _s801CF3C0_41; lwz 0,0x4c(1); mtspr 8,0; lmw 22,0x20(1); addi 1,1,72"

extern "C" void _s801CF3C0_0();
extern "C" void _s801CF3C0_1();
extern "C" void _s801CF3C0_2();
extern "C" void _s801CF3C0_3();
extern "C" void _s801CF3C0_4();
extern "C" void _s801CF3C0_5();
extern "C" void _s801CF3C0_6();
extern "C" void _s801CF3C0_7();
extern "C" void _s801CF3C0_8();
extern "C" void _s801CF3C0_9();
extern "C" void _s801CF3C0_10();
extern "C" void _s801CF3C0_11();
extern "C" void _s801CF3C0_12();
extern "C" void _s801CF3C0_13();
extern "C" void _s801CF3C0_14();
extern "C" void _s801CF3C0_15();
extern "C" void _s801CF3C0_16();
extern "C" void _s801CF3C0_17();
extern "C" void _s801CF3C0_18();
extern "C" void _s801CF3C0_19();
extern "C" void _s801CF3C0_20();
extern "C" void _s801CF3C0_21();
extern "C" void _s801CF3C0_22();
extern "C" void _s801CF3C0_23();
extern "C" void _s801CF3C0_24();
extern "C" void _s801CF3C0_25();
extern "C" void _s801CF3C0_26();
extern "C" void _s801CF3C0_27();
extern "C" void _s801CF3C0_28();
extern "C" void _s801CF3C0_29();
extern "C" void _s801CF3C0_30();
extern "C" void _s801CF3C0_31();
extern "C" void _s801CF3C0_32();
extern "C" void _s801CF3C0_33();
extern "C" void _s801CF3C0_34();
extern "C" void _s801CF3C0_35();
extern "C" void _s801CF3C0_36();
extern "C" void _s801CF3C0_37();
extern "C" void _s801CF3C0_38();
extern "C" void _s801CF3C0_39();
extern "C" void _s801CF3C0_40();
extern "C" void _s801CF3C0_41();

struct O2TTarget {
    void UpdateText();
};

void O2TTarget::UpdateText() {
}
