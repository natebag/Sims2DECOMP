// 0x802AF774 AptTextFormat::objectMemberSet(AptValue (1176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; mr 31,6; cmpwi 4,0; beq 0f; lwz 3,0x0(5); lhz 4,0x2(3); addi 3,3,8; bl _s802AF774_0; b 1f; 0:; li 3,0; 1:; cmpwi 3,0; beq 35f; lwz 3,0x4(3); cmpwi 3,8; beq 20f; bgt 3f; cmpwi 3,4; beq 14f; bgt 2f; cmpwi 3,2; beq 14f; bgt 16f; cmpwi 3,1; beq 5f; b 35f; 2:; cmpwi 3,6; beq 15f; bgt 19f; b 13f; 3:; cmpwi 3,13; bgt 4f; cmpwi 3,12; bge 14f; cmpwi 3,10; beq 26f; bgt 27f; b 14f; 4:; cmpwi 3,15; beq 28f; blt 34f; cmpwi 3,16; beq 14f; b 35f; 5:; lis 11,-32700; addi 4,1,8; lhz 9,-6476(11); addi 0,11,-6476; mr 3,31; stw 0,0x8(1); addi 9,9,1; sth 9,-6476(11); bl _s802AF774_1; lwz 3,0x8(1); lis 4,-32703; addi 4,4,3968; addi 3,3,8; bl _s802AF774_2; cmpwi 3,0; beq 6f; lwz 3,0x8(1); lis 4,-32703; addi 4,4,3976; addi 3,3,8; bl _s802AF774_3; cmpwi 3,0; bne 7f; 6:; li 0,0; b 11f; 7:; lwz 3,0x8(1); lis 4,-32703; addi 4,4,3984; addi 3,3,8; bl _s802AF774_4; cmpwi 3,0; bne 8f; li 0,2; b 11f; 8:; lwz 3,0x8(1); lis 4,-32703; addi 4,4,3992; addi 3,3,8; bl _s802AF774_5; cmpwi 3,0; bne 9f; li 0,1; b 11f; 9:; lwz 3,0x8(1); lis 4,-32703; addi 4,4,4892; addi 3,3,8; bl _s802AF774_6; cmpwi 3,0; beq 10f; lwz 3,0x8(1); lis 4,-32703; addi 4,4,4900; addi 3,3,8; bl _s802AF774_7; cmpwi 3,0; bne 12f; 10:; li 0,3; 11:; stw 0,0x30(30); 12:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 14f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AF774_8; b 14f; 13:; mr 3,31; bl _s802AF774_9; rlwinm 3,3,0,8,31; stw 3,0x2c(30); 14:; li 3,1; b 36f; 15:; mr 3,31; addi 4,30,36; bl _s802AF774_10; b 14b; 16:; lis 11,-32700; addi 4,1,8; lhz 9,-6476(11); addi 0,11,-6476; mr 3,31; stw 0,0x8(1); addi 9,9,1; sth 9,-6476(11); bl _s802AF774_11; lwz 3,0x8(1); lis 4,-32703; addi 4,4,3976; addi 3,3,8; bl _s802AF774_12; cmpwi 3,0; bne 17f; lwz 0,0x34(30); oris 0,0,1; ori 0,0,1; stw 0,0x34(30); 17:; lwz 3,0x8(1); lis 4,-32703; addi 4,4,4892; addi 3,3,8; bl _s802AF774_13; cmpwi 3,0; bne 18f; lwz 0,0x34(30); oris 0,0,1; stw 0,0x34(30); andi. 9,0,1; beq 18f; xori 0,0,1; stw 0,0x34(30); 18:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 14b; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AF774_14; b 14b; 19:; mr 3,31; bl _s802AF774_15; stw 3,0x38(30); b 14b; 20:; lis 11,-32700; addi 4,1,8; lhz 9,-6476(11); addi 0,11,-6476; mr 3,31; stw 0,0x8(1); addi 9,9,1; sth 9,-6476(11); bl _s802AF774_16; lwz 3,0x8(1); lis 4,-32703; addi 4,4,3976; addi 3,3,8; bl _s802AF774_17; cmpwi 3,0; bne 21f; lwz 0,0x34(30); oris 0,0,16; ori 0,0,16; b 24f; 21:; lwz 3,0x8(1); lis 4,-32703; addi 4,4,4892; addi 3,3,8; bl _s802AF774_18; cmpwi 3,0; bne 22f; lwz 0,0x34(30); oris 0,0,16; stw 0,0x34(30); andi. 9,0,16; beq 25f; b 23f; 22:; lwz 0,0x34(30); ori 0,0,16; 23:; xori 0,0,16; 24:; stw 0,0x34(30); 25:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 14b; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AF774_19; b 14b; 26:; mr 3,31; bl _s802AF774_20; stw 3,0x3c(30); b 14b; 27:; mr 3,31; bl _s802AF774_21; stw 3,0x40(30); b 14b; 28:; lis 11,-32700; addi 4,1,8; lhz 9,-6476(11); addi 0,11,-6476; mr 3,31; stw 0,0x8(1); addi 9,9,1; sth 9,-6476(11); bl _s802AF774_22; lwz 3,0x8(1); lis 4,-32703; addi 4,4,3976; addi 3,3,8; bl _s802AF774_23; cmpwi 3,0; bne 29f; lwz 0,0x34(30); oris 0,0,256; ori 0,0,256; b 32f; 29:; lwz 3,0x8(1); lis 4,-32703; addi 4,4,4892; addi 3,3,8; bl _s802AF774_24; cmpwi 3,0; bne 30f; lwz 0,0x34(30); oris 0,0,256; stw 0,0x34(30); andi. 9,0,256; beq 33f; b 31f; 30:; lwz 0,0x34(30); oris 0,0,256; 31:; xori 0,0,256; 32:; stw 0,0x34(30); 33:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 14b; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AF774_25; b 14b; 34:; mr 3,31; bl _s802AF774_26; stfs f1,0x28(30); b 14b; 35:; li 3,0; 36:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802AF774_0();
extern "C" void _s802AF774_1();
extern "C" void _s802AF774_2();
extern "C" void _s802AF774_3();
extern "C" void _s802AF774_4();
extern "C" void _s802AF774_5();
extern "C" void _s802AF774_6();
extern "C" void _s802AF774_7();
extern "C" void _s802AF774_8();
extern "C" void _s802AF774_9();
extern "C" void _s802AF774_10();
extern "C" void _s802AF774_11();
extern "C" void _s802AF774_12();
extern "C" void _s802AF774_13();
extern "C" void _s802AF774_14();
extern "C" void _s802AF774_15();
extern "C" void _s802AF774_16();
extern "C" void _s802AF774_17();
extern "C" void _s802AF774_18();
extern "C" void _s802AF774_19();
extern "C" void _s802AF774_20();
extern "C" void _s802AF774_21();
extern "C" void _s802AF774_22();
extern "C" void _s802AF774_23();
extern "C" void _s802AF774_24();
extern "C" void _s802AF774_25();
extern "C" void _s802AF774_26();
extern "C" void f_802AF774() {}
