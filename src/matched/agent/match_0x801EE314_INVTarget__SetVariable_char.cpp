// 0x801EE314 INVTarget::SetVariable(char (888 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 30,3; lbz 9,0x0(31); mr 29,5; addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 31,31,1; 0:; lis 3,-32704; mr 4,31; addi 3,3,-27628; bl _s801EE314_0; cmpwi 3,0; bne 1f; mr 3,30; mr 4,29; bl _s801EE314_1; b 20f; 1:; lis 3,-32704; mr 4,31; addi 3,3,-27612; bl _s801EE314_2; cmpwi 3,0; bne 2f; mr 3,30; mr 4,29; bl _s801EE314_3; b 20f; 2:; lis 3,-32704; mr 4,31; addi 3,3,-27592; bl _s801EE314_4; cmpwi 3,0; bne 3f; mr 3,30; mr 4,29; bl _s801EE314_5; b 20f; 3:; lis 3,-32704; mr 4,31; addi 3,3,-27576; bl _s801EE314_6; cmpwi 3,0; bne 4f; mr 3,30; mr 4,29; bl _s801EE314_7; b 20f; 4:; lis 3,-32704; mr 4,31; addi 3,3,-27560; bl _s801EE314_8; cmpwi 3,0; bne 5f; mr 3,30; mr 4,29; bl _s801EE314_9; b 20f; 5:; lis 3,-32704; mr 4,31; addi 3,3,-27536; bl _s801EE314_10; cmpwi 3,0; bne 6f; mr 3,30; mr 4,29; bl _s801EE314_11; b 20f; 6:; lis 3,-32704; mr 4,31; addi 3,3,-27512; bl _s801EE314_12; cmpwi 3,0; beq 20f; lis 3,-32704; mr 4,31; addi 3,3,-27500; bl _s801EE314_13; cmpwi 3,0; bne 7f; mr 3,30; mr 4,29; bl _s801EE314_14; b 20f; 7:; lis 3,-32704; mr 4,31; addi 3,3,-27480; bl _s801EE314_15; cmpwi 3,0; bne 8f; mr 3,30; mr 4,29; bl _s801EE314_16; b 20f; 8:; lis 3,-32704; mr 4,31; addi 3,3,-27460; bl _s801EE314_17; cmpwi 3,0; bne 9f; mr 3,30; mr 4,29; bl _s801EE314_18; b 20f; 9:; lis 3,-32704; mr 4,31; addi 3,3,-27440; bl _s801EE314_19; cmpwi 3,0; bne 10f; mr 3,30; mr 4,29; bl _s801EE314_20; b 20f; 10:; lis 3,-32704; mr 4,31; addi 3,3,-27424; bl _s801EE314_21; cmpwi 3,0; bne 11f; mr 3,30; mr 4,29; bl _s801EE314_22; b 20f; 11:; lis 3,-32704; mr 4,31; addi 3,3,-27404; bl _s801EE314_23; cmpwi 3,0; bne 12f; mr 3,30; mr 4,29; bl _s801EE314_24; b 20f; 12:; lis 3,-32704; mr 4,31; addi 3,3,-27384; bl _s801EE314_25; cmpwi 3,0; bne 13f; mr 3,30; mr 4,29; bl _s801EE314_26; b 20f; 13:; lis 3,-32704; mr 4,31; addi 3,3,-27364; bl _s801EE314_27; cmpwi 3,0; bne 14f; mr 3,30; mr 4,29; bl _s801EE314_28; b 20f; 14:; lis 3,-32704; mr 4,31; addi 3,3,-27344; bl _s801EE314_29; cmpwi 3,0; bne 15f; mr 3,30; mr 4,29; bl _s801EE314_30; b 20f; 15:; lis 3,-32704; mr 4,31; addi 3,3,-27320; bl _s801EE314_31; cmpwi 3,0; bne 16f; mr 3,30; mr 4,29; bl _s801EE314_32; b 20f; 16:; lis 3,-32704; mr 4,31; addi 3,3,-27292; bl _s801EE314_33; cmpwi 3,0; bne 17f; mr 3,30; mr 4,29; bl _s801EE314_34; b 20f; 17:; lis 3,-32704; mr 4,31; addi 3,3,-27264; bl _s801EE314_35; cmpwi 3,0; bne 18f; mr 3,30; mr 4,29; bl _s801EE314_36; b 20f; 18:; lis 3,-32704; mr 4,31; addi 3,3,-27240; bl _s801EE314_37; cmpwi 3,0; bne 19f; mr 3,30; mr 4,29; bl _s801EE314_38; b 20f; 19:; lis 3,-32704; mr 4,31; addi 3,3,-27216; bl _s801EE314_39; cmpwi 3,0; bne 20f; mr 3,30; mr 4,29; bl _s801EE314_40; 20:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801EE314_0();
extern "C" void _s801EE314_1();
extern "C" void _s801EE314_2();
extern "C" void _s801EE314_3();
extern "C" void _s801EE314_4();
extern "C" void _s801EE314_5();
extern "C" void _s801EE314_6();
extern "C" void _s801EE314_7();
extern "C" void _s801EE314_8();
extern "C" void _s801EE314_9();
extern "C" void _s801EE314_10();
extern "C" void _s801EE314_11();
extern "C" void _s801EE314_12();
extern "C" void _s801EE314_13();
extern "C" void _s801EE314_14();
extern "C" void _s801EE314_15();
extern "C" void _s801EE314_16();
extern "C" void _s801EE314_17();
extern "C" void _s801EE314_18();
extern "C" void _s801EE314_19();
extern "C" void _s801EE314_20();
extern "C" void _s801EE314_21();
extern "C" void _s801EE314_22();
extern "C" void _s801EE314_23();
extern "C" void _s801EE314_24();
extern "C" void _s801EE314_25();
extern "C" void _s801EE314_26();
extern "C" void _s801EE314_27();
extern "C" void _s801EE314_28();
extern "C" void _s801EE314_29();
extern "C" void _s801EE314_30();
extern "C" void _s801EE314_31();
extern "C" void _s801EE314_32();
extern "C" void _s801EE314_33();
extern "C" void _s801EE314_34();
extern "C" void _s801EE314_35();
extern "C" void _s801EE314_36();
extern "C" void _s801EE314_37();
extern "C" void _s801EE314_38();
extern "C" void _s801EE314_39();
extern "C" void _s801EE314_40();
extern "C" void f_801EE314() {}
