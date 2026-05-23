// 0x8005EE34 SAnimator2::ReconStream(ReconBuffer (1708 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-176(1); mfspr 0,8; stmw 17,0x74(1); stw 0,0xb4(1); mr 31,5; mr 25,3; mr 28,4; cmpwi 31,63; bgt 7f; addi 4,1,36; mr 3,28; li 5,1; bl _s8005EE34_0; mr 3,28; addi 4,1,40; li 5,1; bl _s8005EE34_1; lwz 0,0xc(28); cmpwi 0,0; beq 0f; li 0,0; 0:; stw 0,0x2c(1); addi 31,1,24; addi 27,1,44; mr 30,31; addi 26,1,48; addi 24,1,52; addi 23,1,56; addi 22,1,60; addi 21,1,12; addi 20,1,16; addi 19,1,64; addi 18,1,68; addi 17,1,72; li 29,5; 1:; mr 3,30; bl _s8005EE34_2; mr 3,28; mr 4,30; bl _s8005EE34_3; mr 3,28; mr 4,30; bl _s8005EE34_4; mr 3,30; li 4,2; bl _s8005EE34_5; addic. 29,29,-1; bne 1b; mr 4,27; mr 3,28; li 5,1; li 29,0; bl _s8005EE34_6; lwz 0,0x2c(1); cmpw 29,0; bge 3f; mr 30,31; 2:; mr 3,30; addi 29,29,1; bl _s8005EE34_7; mr 3,28; mr 4,30; bl _s8005EE34_8; mr 3,28; mr 4,30; bl _s8005EE34_9; mr 3,30; li 4,2; bl _s8005EE34_10; lwz 0,0x2c(1); cmpw 29,0; blt 2b; 3:; lwz 0,0xc(28); cmpwi 0,0; bne 4f; mr 3,31; bl _s8005EE34_11; mr 3,28; mr 4,31; bl _s8005EE34_12; mr 3,28; mr 4,31; bl _s8005EE34_13; mr 3,28; mr 4,31; bl _s8005EE34_14; mr 3,31; li 4,2; bl _s8005EE34_15; b 5f; 4:; mr 3,31; bl _s8005EE34_16; mr 3,28; mr 4,31; bl _s8005EE34_17; mr 3,28; mr 4,31; bl _s8005EE34_18; mr 3,28; mr 4,31; bl _s8005EE34_19; mr 3,31; li 4,2; bl _s8005EE34_20; 5:; mr 4,26; mr 3,28; li 5,1; bl _s8005EE34_21; lwz 0,0xc(28); cmpwi 0,0; bne 6f; lwz 0,0x30(1); cmpwi 0,0; beq 6f; cmpwi 0,3; beq 6f; cmpwi 0,1; beq 6f; cmpwi 0,2; beq 6f; li 0,3; stw 0,0x30(1); 6:; mr 4,24; mr 3,28; li 5,1; bl _s8005EE34_22; mr 4,23; mr 3,28; li 5,1; bl _s8005EE34_23; mr 4,22; mr 3,28; li 5,1; bl _s8005EE34_24; addi 4,1,8; mr 3,28; li 5,1; bl _s8005EE34_25; mr 4,21; mr 3,28; li 5,1; bl _s8005EE34_26; mr 4,20; mr 3,28; li 5,1; bl _s8005EE34_27; mr 4,19; mr 3,28; li 5,1; bl _s8005EE34_28; mr 4,18; mr 3,28; li 5,1; bl _s8005EE34_29; mr 4,17; mr 3,28; li 5,1; bl _s8005EE34_30; b 32f; 7:; lwz 0,0xc(28); cmpwi 0,0; bne 28f; mr 3,28; addi 4,1,32; li 5,1; li 26,0; bl _s8005EE34_31; addi 19,25,1516; cmpwi 31,96; lha 0,0x20(1); mfcr 17; addi 22,1,88; addi 21,1,92; addi 20,1,96; cmpw 26,0; addi 18,1,100; bge 23f; lis 23,-32692; 8:; li 3,12; bl _s8005EE34_32; mr 9,3; addi 4,9,4; stw 9,0x4c(1); mr 3,28; bl _s8005EE34_33; lwz 4,0x4c(1); mr 3,28; li 5,1; bl _s8005EE34_34; lwz 9,0x4c(1); addi 3,23,-27556; lwz 4,0x0(9); bl _s8005EE34_35; cmpwi 3,0; beq 21f; addi 31,25,360; addi 24,1,76; lwz 30,0x4(31); lwz 0,0xc(31); cmpw 30,0; beq 9f; lwz 0,0x4c(1); addi 26,26,1; stw 0,0x0(30); lwz 9,0x4(31); addi 9,9,4; stw 9,0x4(31); b 20f; 9:; lwz 0,0x168(25); li 9,1; stw 9,0x54(1); addi 10,1,84; subf 0,0,30; addi 11,1,80; srawi 9,0,2; stw 9,0x50(1); cmplwi 9,1; bge 10f; mr 11,10; 10:; lwz 0,0x0(11); add. 0,9,0; beq 12f; rlwinm 0,0,2,0,29; mr 27,0; cmplwi 0,128; ble 11f; mr 3,27; bl _s8005EE34_36; mr 29,3; b 13f; 11:; mr 3,27; bl _s8005EE34_37; mr 29,3; b 13f; 12:; li 29,0; li 27,0; 13:; lwz 4,0x0(31); cmpw 30,4; beq 14f; subf 30,4,30; mr 3,29; mr 5,30; bl _s8005EE34_38; add 0,3,30; b 15f; 14:; mr 0,29; 15:; lwz 9,0x54(1); mr 30,0; addi 26,26,1; mtspr 9,9; cmpwi 9,0; beq 17f; 16:; lwz 0,0x0(24); stw 0,0x0(30); addi 30,30,4; bdnz 16b; 17:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 19f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 18f; bl _s8005EE34_39; b 19f; 18:; bl _s8005EE34_40; 19:; add 0,27,29; stw 29,0x0(31); stw 0,0xc(31); stw 30,0x4(31); 20:; lwz 9,0x4c(1); addi 3,23,-27556; lwz 4,0x0(9); bl _s8005EE34_41; lwz 9,0x4c(1); stw 3,0x8(9); b 22f; 21:; lwz 3,0x4c(1); addi 26,26,1; bl _s8005EE34_42; 22:; lha 0,0x20(1); cmpw 26,0; blt 8b; 23:; li 0,0; mr 4,22; stw 0,0x58(1); mr 3,28; bl _s8005EE34_43; mr 4,21; mr 3,28; li 5,1; bl _s8005EE34_44; mr 4,20; mr 3,28; li 5,1; bl _s8005EE34_45; mr 4,19; mr 3,28; li 5,1; bl _s8005EE34_46; mr 4,18; mr 3,28; li 5,1; bl _s8005EE34_47; lwz 0,0x58(1); cmpwi 0,0; beq 24f; lfs f0,0x5c(1); li 11,1; lwz 0,0x60(1); lwz 9,0x64(1); stfs f0,0xd0(25); stw 0,0xc8(25); stw 11,0x5f0(25); stw 9,0xf0(25); b 25f; 24:; stw 0,0x5ec(25); 25:; mtcrf 128,17; ble 32f; lwz 9,0x604(25); li 0,1; stw 0,0x68(1); cmpwi 9,0; bne 26f; stw 9,0x68(1); 26:; mr 3,28; addi 4,1,104; bl _s8005EE34_48; lwz 0,0x68(1); cmpwi 0,0; beq 32f; lwz 3,0x604(25); cmpwi 3,0; beq 27f; bl _s8005EE34_49; li 0,0; stw 0,0x604(25); 27:; li 3,292; bl _s8005EE34_50; bl _s8005EE34_51; mr 0,3; mr 4,28; stw 0,0x604(25); li 5,2; bl _s8005EE34_52; b 32f; 28:; lwz 0,0x16c(25); mr 3,28; lwz 9,0x168(25); addi 4,1,34; li 5,1; li 27,0; subf 0,9,0; addi 26,25,236; srawi 0,0,2; addi 24,25,208; sth 0,0x22(1); addi 31,25,200; bl _s8005EE34_53; addi 23,25,1512; lha 0,0x22(1); addi 22,25,240; addi 21,1,108; cmpw 27,0; bge 30f; li 29,0; 29:; lwz 9,0x168(25); mr 3,28; addi 27,27,1; lwzx 30,9,29; addi 29,29,4; addi 4,30,4; bl _s8005EE34_54; mr 4,30; mr 3,28; li 5,1; bl _s8005EE34_55; lha 0,0x22(1); cmpw 27,0; blt 29b; 30:; mr 4,26; mr 3,28; bl _s8005EE34_56; mr 4,24; mr 3,28; li 5,1; bl _s8005EE34_57; mr 4,31; mr 3,28; li 5,1; bl _s8005EE34_58; mr 4,23; mr 3,28; li 5,1; bl _s8005EE34_59; mr 4,22; mr 3,28; li 5,1; bl _s8005EE34_60; lwz 9,0x604(25); li 0,1; stw 0,0x6c(1); cmpwi 9,0; bne 31f; stw 9,0x6c(1); 31:; mr 4,21; mr 3,28; bl _s8005EE34_61; lwz 0,0x6c(1); cmpwi 0,0; beq 32f; lwz 3,0x604(25); mr 4,28; li 5,2; bl _s8005EE34_62; 32:; lwz 0,0xc(28); cmpwi 0,0; bne 33f; li 0,1; stw 0,0x5f4(25); 33:; lwz 0,0xb4(1); mtspr 8,0; lmw 17,0x74(1); addi 1,1,176"

extern "C" void _s8005EE34_0();
extern "C" void _s8005EE34_1();
extern "C" void _s8005EE34_2();
extern "C" void _s8005EE34_3();
extern "C" void _s8005EE34_4();
extern "C" void _s8005EE34_5();
extern "C" void _s8005EE34_6();
extern "C" void _s8005EE34_7();
extern "C" void _s8005EE34_8();
extern "C" void _s8005EE34_9();
extern "C" void _s8005EE34_10();
extern "C" void _s8005EE34_11();
extern "C" void _s8005EE34_12();
extern "C" void _s8005EE34_13();
extern "C" void _s8005EE34_14();
extern "C" void _s8005EE34_15();
extern "C" void _s8005EE34_16();
extern "C" void _s8005EE34_17();
extern "C" void _s8005EE34_18();
extern "C" void _s8005EE34_19();
extern "C" void _s8005EE34_20();
extern "C" void _s8005EE34_21();
extern "C" void _s8005EE34_22();
extern "C" void _s8005EE34_23();
extern "C" void _s8005EE34_24();
extern "C" void _s8005EE34_25();
extern "C" void _s8005EE34_26();
extern "C" void _s8005EE34_27();
extern "C" void _s8005EE34_28();
extern "C" void _s8005EE34_29();
extern "C" void _s8005EE34_30();
extern "C" void _s8005EE34_31();
extern "C" void _s8005EE34_32();
extern "C" void _s8005EE34_33();
extern "C" void _s8005EE34_34();
extern "C" void _s8005EE34_35();
extern "C" void _s8005EE34_36();
extern "C" void _s8005EE34_37();
extern "C" void _s8005EE34_38();
extern "C" void _s8005EE34_39();
extern "C" void _s8005EE34_40();
extern "C" void _s8005EE34_41();
extern "C" void _s8005EE34_42();
extern "C" void _s8005EE34_43();
extern "C" void _s8005EE34_44();
extern "C" void _s8005EE34_45();
extern "C" void _s8005EE34_46();
extern "C" void _s8005EE34_47();
extern "C" void _s8005EE34_48();
extern "C" void _s8005EE34_49();
extern "C" void _s8005EE34_50();
extern "C" void _s8005EE34_51();
extern "C" void _s8005EE34_52();
extern "C" void _s8005EE34_53();
extern "C" void _s8005EE34_54();
extern "C" void _s8005EE34_55();
extern "C" void _s8005EE34_56();
extern "C" void _s8005EE34_57();
extern "C" void _s8005EE34_58();
extern "C" void _s8005EE34_59();
extern "C" void _s8005EE34_60();
extern "C" void _s8005EE34_61();
extern "C" void _s8005EE34_62();

struct SAnimator2 {
    void ReconStream();
};

void SAnimator2::ReconStream() {
}
