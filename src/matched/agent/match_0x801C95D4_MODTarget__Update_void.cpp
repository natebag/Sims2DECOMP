// 0x801C95D4 MODTarget::Update(void) (1080 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); mr 31,3; lwz 0,0x84(31); cmpwi 0,0; beq 12f; lwz 0,0x8c(31); cmpwi 0,0; bne 5f; lwz 0,0x90(31); cmpwi 0,0; beq 3f; lwz 0,0x88(31); cmpwi 0,0; bne 2f; lis 9,-32697; lwz 4,0x94(31); addi 28,9,23428; lwz 3,0x48(28); bl _s801C95D4_0; cmpwi 3,0; beq 2f; addi 30,31,200; lwz 6,0x94(31); lis 4,-32705; li 5,12; addi 4,4,12564; mr 3,30; bl _s801C95D4_1; mr 29,30; mr 3,30; bl _s801C95D4_2; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12548; mr 3,30; bl _s801C95D4_3; mr 3,30; li 4,1; bl _s801C95D4_4; lwz 0,0x94(31); cmpwi 0,0; beq 0f; li 4,320; mr 3,29; bl _s801C95D4_5; lis 4,-32705; lwz 5,0x94(31); addi 4,4,12576; mr 3,29; bl _s801C95D4_6; mr 3,29; li 4,0; bl _s801C95D4_7; b 1f; 0:; lwz 0,0xec(28); cmpwi 0,0; beq 1f; lis 4,-32705; li 5,0; addi 4,4,12576; mr 3,29; bl _s801C95D4_8; mr 3,29; li 4,120; bl _s801C95D4_9; li 4,20; mr 3,29; bl _s801C95D4_10; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12604; mr 3,29; bl _s801C95D4_11; li 4,294; mr 3,29; bl _s801C95D4_12; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12620; mr 3,29; bl _s801C95D4_13; li 4,308; mr 3,29; bl _s801C95D4_14; lis 4,-32705; lwz 5,0x94(31); addi 4,4,12632; mr 3,29; bl _s801C95D4_15; mr 3,29; li 4,308; bl _s801C95D4_16; 1:; mr 3,29; bl _s801C95D4_17; lwz 7,-30124(13); lis 4,-32705; lwz 8,0x94(31); li 5,250; li 6,0; addi 4,4,12548; mr 3,29; bl _s801C95D4_18; mr 3,29; li 4,255; bl _s801C95D4_19; mr 3,29; bl _s801C95D4_20; li 0,1; stw 0,0x88(31); b 4f; 2:; lwz 0,0x90(31); cmpwi 0,0; bne 5f; 3:; lwz 0,0x88(31); cmpwi 0,0; beq 5f; addi 30,31,200; lwz 7,-30112(13); lwz 8,0x94(31); lis 4,-32705; li 5,250; li 6,0; addi 4,4,12548; mr 3,30; bl _s801C95D4_21; mr 3,30; li 4,0; bl _s801C95D4_22; mr 3,30; bl _s801C95D4_23; li 0,1; 4:; stw 0,0x8c(31); 5:; lwz 0,0x94(31); cmpwi 0,0; bne 7f; lwz 9,0xe4(31); cmpwi 9,0; ble 6f; addi 0,9,-1; cmpwi 0,0; stw 0,0xe4(31); bne 6f; addi 3,1,8; bl _s801C95D4_24; lis 4,-32705; addi 3,1,8; addi 4,4,12648; li 5,0; li 6,0; bl _s801C95D4_25; addi 3,1,8; li 4,2; bl _s801C95D4_26; 6:; lwz 9,0xe0(31); cmpwi 9,0; ble 7f; addi 0,9,-1; cmpwi 0,0; stw 0,0xe0(31); bne 7f; addi 3,1,8; bl _s801C95D4_27; lis 4,-32705; addi 3,1,8; addi 4,4,12668; li 5,0; li 6,0; bl _s801C95D4_28; addi 3,1,8; li 4,2; bl _s801C95D4_29; 7:; lwz 9,0xe8(31); cmpwi 9,0; beq 9f; lwz 0,0x94(31); cmpwi 0,0; bne 9f; addi 0,9,-1; cmpwi 0,0; stw 0,0xe8(31); bne 8f; addi 30,31,200; lis 4,-32705; lis 5,-32705; addi 4,4,12604; addi 5,5,12684; mr 3,30; li 6,0; bl _s801C95D4_30; lwz 6,0x94(31); lis 4,-32705; addi 4,4,12632; mr 3,30; li 5,0; bl _s801C95D4_31; lis 4,-32705; lwz 6,0x94(31); mr 3,30; addi 4,4,12620; li 5,1; bl _s801C95D4_32; 8:; lwz 9,0xec(31); lwz 0,0xf0(31); cmpw 9,0; beq 9f; lis 4,-32705; lwz 6,0x94(31); addi 4,4,12632; addi 3,31,200; li 5,11; bl _s801C95D4_33; lwz 0,0xec(31); stw 0,0xf0(31); 9:; lwz 9,0xf8(31); lwz 0,0xfc(31); cmpw 9,0; beq 12f; lwz 0,0xf4(31); cmpwi 0,0; bne 12f; addi 3,1,8; bl _s801C95D4_34; lwz 0,0xf8(31); cmpwi 0,0; beq 10f; lis 30,-32705; lwz 6,0x94(31); addi 3,1,8; addi 4,30,12520; li 5,1; bl _s801C95D4_35; lwz 7,-30148(13); addi 3,1,8; lwz 8,0x94(31); addi 4,30,12520; li 5,250; li 6,0; bl _s801C95D4_36; addi 3,1,8; li 4,255; bl _s801C95D4_37; addi 3,1,8; bl _s801C95D4_38; b 11f; 10:; lwz 7,-30136(13); lis 4,-32705; lwz 8,0x94(31); addi 3,1,8; addi 4,4,12520; li 5,250; li 6,0; bl _s801C95D4_39; addi 3,1,8; li 4,0; bl _s801C95D4_40; addi 3,1,8; bl _s801C95D4_41; 11:; li 0,1; addi 3,1,8; stw 0,0xf4(31); li 4,2; bl _s801C95D4_42; 12:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s801C95D4_0();
extern "C" void _s801C95D4_1();
extern "C" void _s801C95D4_2();
extern "C" void _s801C95D4_3();
extern "C" void _s801C95D4_4();
extern "C" void _s801C95D4_5();
extern "C" void _s801C95D4_6();
extern "C" void _s801C95D4_7();
extern "C" void _s801C95D4_8();
extern "C" void _s801C95D4_9();
extern "C" void _s801C95D4_10();
extern "C" void _s801C95D4_11();
extern "C" void _s801C95D4_12();
extern "C" void _s801C95D4_13();
extern "C" void _s801C95D4_14();
extern "C" void _s801C95D4_15();
extern "C" void _s801C95D4_16();
extern "C" void _s801C95D4_17();
extern "C" void _s801C95D4_18();
extern "C" void _s801C95D4_19();
extern "C" void _s801C95D4_20();
extern "C" void _s801C95D4_21();
extern "C" void _s801C95D4_22();
extern "C" void _s801C95D4_23();
extern "C" void _s801C95D4_24();
extern "C" void _s801C95D4_25();
extern "C" void _s801C95D4_26();
extern "C" void _s801C95D4_27();
extern "C" void _s801C95D4_28();
extern "C" void _s801C95D4_29();
extern "C" void _s801C95D4_30();
extern "C" void _s801C95D4_31();
extern "C" void _s801C95D4_32();
extern "C" void _s801C95D4_33();
extern "C" void _s801C95D4_34();
extern "C" void _s801C95D4_35();
extern "C" void _s801C95D4_36();
extern "C" void _s801C95D4_37();
extern "C" void _s801C95D4_38();
extern "C" void _s801C95D4_39();
extern "C" void _s801C95D4_40();
extern "C" void _s801C95D4_41();
extern "C" void _s801C95D4_42();
extern "C" void f_801C95D4() {}
