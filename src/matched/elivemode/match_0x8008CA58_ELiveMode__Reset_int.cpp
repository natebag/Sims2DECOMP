// 0x8008CA58 ELiveMode::Reset(int) (568 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; bl _s8008CA58_0; bl _s8008CA58_1; bl _s8008CA58_2; bl _s8008CA58_3; bl _s8008CA58_4; bl _s8008CA58_5; bl _s8008CA58_6; bl _s8008CA58_7; bl _s8008CA58_8; bl _s8008CA58_9; bl _s8008CA58_10; bl _s8008CA58_11; bl _s8008CA58_12; bl _s8008CA58_13; bl _s8008CA58_14; bl _s8008CA58_15; bl _s8008CA58_16; bl _s8008CA58_17; bl _s8008CA58_18; bl _s8008CA58_19; bl _s8008CA58_20; bl _s8008CA58_21; bl _s8008CA58_22; bl _s8008CA58_23; bl _s8008CA58_24; bl _s8008CA58_25; bl _s8008CA58_26; lwz 3,-24508(13); cmpwi 3,0; beq 0f; addi 3,3,48; li 4,32; bl _s8008CA58_27; lwz 3,-24508(13); li 4,32; addi 3,3,48; bl _s8008CA58_28; 0:; lwz 3,-21492(13); li 4,3; li 30,0; bl _s8008CA58_29; bl _s8008CA58_30; lis 9,-32697; addi 31,9,24012; lwz 3,0x110(31); stw 30,0x160(31); bl _s8008CA58_31; lwz 3,0x44(29); cmpwi 3,0; beq 1f; bl _s8008CA58_32; stw 30,0x44(29); 1:; bl _s8008CA58_33; bl _s8008CA58_34; lwz 3,0xc8(31); stw 30,0xd0(31); cmpwi 3,0; beq 2f; li 4,3; bl _s8008CA58_35; stw 30,0xc8(31); 2:; lwz 11,-21484(13); li 0,1; stw 0,0x34(29); stw 30,0x30(29); cmpwi 11,0; beq 3f; lwz 9,0x0(11); lha 3,0x280(9); lwz 0,0x284(9); add 3,11,3; mtspr 8,0; blrl; 3:; lwz 31,-21508(13); cmpwi 31,0; beq 4f; lwz 9,0x0(31); lha 3,0x40(9); lwz 0,0x44(9); add 3,31,3; mtspr 8,0; blrl; 4:; bl _s8008CA58_36; lwz 3,-22708(13); bl _s8008CA58_37; lwz 3,-22704(13); bl _s8008CA58_38; lwz 3,-22700(13); bl _s8008CA58_39; lwz 3,-22708(13); bl _s8008CA58_40; lwz 3,-22704(13); bl _s8008CA58_41; lwz 3,-22700(13); bl _s8008CA58_42; bl _s8008CA58_43; bl _s8008CA58_44; lwz 9,0x0(31); lha 3,0xc8(9); lwz 0,0xcc(9); add 3,31,3; mtspr 8,0; blrl; lwz 3,-21472(13); bl _s8008CA58_45; bl _s8008CA58_46; bl _s8008CA58_47; bl _s8008CA58_48; bl _s8008CA58_49; bl _s8008CA58_50; bl _s8008CA58_51; bl _s8008CA58_52; bl _s8008CA58_53; bl _s8008CA58_54; bl _s8008CA58_55; bl _s8008CA58_56; bl _s8008CA58_57; bl _s8008CA58_58; bl _s8008CA58_59; bl _s8008CA58_60; bl _s8008CA58_61; bl _s8008CA58_62; bl _s8008CA58_63; bl _s8008CA58_64; bl _s8008CA58_65; bl _s8008CA58_66; bl _s8008CA58_67; bl _s8008CA58_68; bl _s8008CA58_69; bl _s8008CA58_70; bl _s8008CA58_71; bl _s8008CA58_72; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8008CA58_0();
extern "C" void _s8008CA58_1();
extern "C" void _s8008CA58_2();
extern "C" void _s8008CA58_3();
extern "C" void _s8008CA58_4();
extern "C" void _s8008CA58_5();
extern "C" void _s8008CA58_6();
extern "C" void _s8008CA58_7();
extern "C" void _s8008CA58_8();
extern "C" void _s8008CA58_9();
extern "C" void _s8008CA58_10();
extern "C" void _s8008CA58_11();
extern "C" void _s8008CA58_12();
extern "C" void _s8008CA58_13();
extern "C" void _s8008CA58_14();
extern "C" void _s8008CA58_15();
extern "C" void _s8008CA58_16();
extern "C" void _s8008CA58_17();
extern "C" void _s8008CA58_18();
extern "C" void _s8008CA58_19();
extern "C" void _s8008CA58_20();
extern "C" void _s8008CA58_21();
extern "C" void _s8008CA58_22();
extern "C" void _s8008CA58_23();
extern "C" void _s8008CA58_24();
extern "C" void _s8008CA58_25();
extern "C" void _s8008CA58_26();
extern "C" void _s8008CA58_27();
extern "C" void _s8008CA58_28();
extern "C" void _s8008CA58_29();
extern "C" void _s8008CA58_30();
extern "C" void _s8008CA58_31();
extern "C" void _s8008CA58_32();
extern "C" void _s8008CA58_33();
extern "C" void _s8008CA58_34();
extern "C" void _s8008CA58_35();
extern "C" void _s8008CA58_36();
extern "C" void _s8008CA58_37();
extern "C" void _s8008CA58_38();
extern "C" void _s8008CA58_39();
extern "C" void _s8008CA58_40();
extern "C" void _s8008CA58_41();
extern "C" void _s8008CA58_42();
extern "C" void _s8008CA58_43();
extern "C" void _s8008CA58_44();
extern "C" void _s8008CA58_45();
extern "C" void _s8008CA58_46();
extern "C" void _s8008CA58_47();
extern "C" void _s8008CA58_48();
extern "C" void _s8008CA58_49();
extern "C" void _s8008CA58_50();
extern "C" void _s8008CA58_51();
extern "C" void _s8008CA58_52();
extern "C" void _s8008CA58_53();
extern "C" void _s8008CA58_54();
extern "C" void _s8008CA58_55();
extern "C" void _s8008CA58_56();
extern "C" void _s8008CA58_57();
extern "C" void _s8008CA58_58();
extern "C" void _s8008CA58_59();
extern "C" void _s8008CA58_60();
extern "C" void _s8008CA58_61();
extern "C" void _s8008CA58_62();
extern "C" void _s8008CA58_63();
extern "C" void _s8008CA58_64();
extern "C" void _s8008CA58_65();
extern "C" void _s8008CA58_66();
extern "C" void _s8008CA58_67();
extern "C" void _s8008CA58_68();
extern "C" void _s8008CA58_69();
extern "C" void _s8008CA58_70();
extern "C" void _s8008CA58_71();
extern "C" void _s8008CA58_72();

struct ELiveMode {
    void Reset();
};

void ELiveMode::Reset() {
}
