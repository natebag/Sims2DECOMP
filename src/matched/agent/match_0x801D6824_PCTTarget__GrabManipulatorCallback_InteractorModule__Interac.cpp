// 0x801D6824 PCTTarget::GrabManipulatorCallback(InteractorModule::Interactor::CallbackData (1468 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 28,0x68(1); stw 0,0x7c(1); lwz 30,0x0(4); mr 31,3; cmpwi 30,1; beq 2f; bgt 0f; cmpwi 30,0; beq 2f; b 28f; 0:; cmpwi 30,2; beq 4f; cmpwi 30,3; bne 28f; bl _s801D6824_0; lwz 4,0x84(31); bl _s801D6824_1; li 4,1; mr 3,31; bl _s801D6824_2; li 3,0; crxor 6,6,6; bl _s801D6824_3; lis 3,30424; ori 3,3,7210; bl _s801D6824_4; 1:; li 3,1; b 29f; 2:; lwz 3,0x214(31); cmpwi 3,0; beq 3f; li 4,0; bl _s801D6824_5; lwz 3,0x214(31); li 4,0; bl _s801D6824_6; 3:; li 3,0; crxor 6,6,6; bl _s801D6824_7; b 1b; 4:; lwz 4,0xc(4); cmpwi 4,0; beq 1b; lwz 9,0x4(4); lwz 0,0x464(9); lha 3,0x460(9); mtspr 8,0; add 3,4,3; blrl; lis 9,-32697; addi 29,9,24012; lwz 0,0x3bc(29); cmpwi 0,0; beq 5f; li 3,1; 5:; li 9,1; li 0,0; stw 0,0x108(31); cmpwi 3,0; stw 30,0xf4(31); stw 9,0xf8(31); stw 9,0x100(31); beq 16f; lis 5,-32705; mr 4,29; addi 3,1,24; addi 5,5,18420; crxor 6,6,6; bl _s801D6824_8; addi 30,31,288; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 6f; lwz 4,0x0(9); 6:; mr 3,30; bl _s801D6824_9; addi 30,31,284; lis 5,-32705; mr 4,29; addi 3,1,28; addi 5,5,18444; crxor 6,6,6; bl _s801D6824_10; lwz 9,0x1c(1); li 4,0; cmpwi 9,0; beq 7f; lwz 4,0x0(9); 7:; mr 3,30; bl _s801D6824_11; addi 30,31,292; lis 5,-32705; mr 4,29; addi 3,1,32; addi 5,5,-1344; crxor 6,6,6; bl _s801D6824_12; lwz 9,0x20(1); li 4,0; cmpwi 9,0; beq 8f; lwz 4,0x0(9); 8:; mr 3,30; bl _s801D6824_13; addi 30,31,296; lis 5,-32705; mr 4,29; addi 5,5,-1340; addi 3,1,36; crxor 6,6,6; bl _s801D6824_14; lwz 9,0x24(1); li 4,0; cmpwi 9,0; beq 9f; lwz 4,0x0(9); 9:; mr 3,30; bl _s801D6824_15; lis 9,-32705; lis 11,-32708; addi 9,9,18468; addi 4,1,40; lwz 7,0x0(9); lwz 8,0x4(9); addi 30,11,-26360; stw 31,0x10(1); cmpwi 31,0; stw 7,0x28(1); stw 8,0x2c(1); beq 10f; addi 3,1,8; li 5,8; bl _s801D6824_16; b 11f; 10:; stw 31,0x8(1); 11:; stw 30,0x14(1); lis 9,-32705; addi 11,1,8; lwz 5,0x8(1); addi 9,9,6448; lwz 4,0x4(11); lwz 3,0x8(11); addi 10,31,324; lwz 8,0xc(11); addi 0,31,244; lwz 6,0x0(9); lwz 7,0x4(9); mr 29,11; stw 5,0x144(31); lis 9,-32709; stw 8,0xc(10); addi 28,9,14552; stw 4,0x4(10); mr 30,0; stw 3,0x8(10); addi 9,1,48; cmpwi 0,0; stw 6,0x30(1); stw 7,0x34(1); stw 0,0x10(1); beq 12f; mr 4,9; mr 3,29; li 5,8; bl _s801D6824_17; b 13f; 12:; stw 30,0x8(1); 13:; stw 28,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-1960; lwz 5,0x4(29); addi 11,31,340; lwz 10,0x8(29); addi 4,1,56; lwz 0,0xc(29); cmpwi 30,0; stw 6,0x154(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32709; stw 5,0x4(11); addi 28,9,14552; stw 10,0x8(11); stw 7,0x38(1); stw 8,0x3c(1); stw 30,0x10(1); beq 14f; mr 3,29; li 5,8; bl _s801D6824_18; b 15f; 14:; stw 30,0x8(1); 15:; stw 28,0x14(1); addi 9,31,356; lwz 8,0x8(1); li 7,0; lwz 0,0xc(29); lwz 11,0x4(29); lwz 10,0x8(29); stw 8,0x164(31); stw 0,0xc(9); stw 11,0x4(9); stw 10,0x8(9); b 27f; 16:; lis 5,-32705; mr 4,29; addi 3,1,64; addi 5,5,18476; crxor 6,6,6; bl _s801D6824_19; addi 30,31,288; lwz 9,0x40(1); li 4,0; cmpwi 9,0; beq 17f; lwz 4,0x0(9); 17:; mr 3,30; bl _s801D6824_20; addi 30,31,284; lis 5,-32705; mr 4,29; addi 3,1,68; addi 5,5,18504; crxor 6,6,6; bl _s801D6824_21; lwz 9,0x44(1); li 4,0; cmpwi 9,0; beq 18f; lwz 4,0x0(9); 18:; mr 3,30; bl _s801D6824_22; addi 30,31,292; lis 5,-32705; mr 4,29; addi 3,1,72; addi 5,5,-1344; crxor 6,6,6; bl _s801D6824_23; lwz 9,0x48(1); li 4,0; cmpwi 9,0; beq 19f; lwz 4,0x0(9); 19:; mr 3,30; bl _s801D6824_24; addi 30,31,296; lis 5,-32705; mr 4,29; addi 5,5,-1340; addi 3,1,76; crxor 6,6,6; bl _s801D6824_25; lwz 9,0x4c(1); li 4,0; cmpwi 9,0; beq 20f; lwz 4,0x0(9); 20:; mr 3,30; bl _s801D6824_26; lis 9,-32705; cmpwi 31,0; addi 9,9,18532; lis 10,-32708; lwz 11,0x0(9); lwz 12,0x4(9); mfcr 30; addi 4,1,80; addi 29,10,-26360; stw 31,0x10(1); stw 11,0x50(1); stw 12,0x54(1); beq 21f; addi 3,1,8; li 5,8; bl _s801D6824_27; b 22f; 21:; stw 31,0x8(1); 22:; lis 9,-32705; stw 29,0x14(1); addi 9,9,18248; addi 11,1,8; lwz 4,0x8(1); addi 8,31,324; lwz 6,0x0(9); lwz 7,0x4(9); lis 10,-32708; lwz 5,0x4(11); mr 29,11; lwz 9,0x8(11); addi 28,10,-26600; lwz 0,0xc(11); mtcrf 128,30; stw 4,0x144(31); addi 11,1,88; stw 0,0xc(8); stw 5,0x4(8); stw 9,0x8(8); stw 6,0x58(1); stw 7,0x5c(1); stw 31,0x10(1); beq 23f; mr 4,11; mr 3,29; li 5,8; bl _s801D6824_28; b 24f; 23:; stw 31,0x8(1); 24:; stw 28,0x14(1); lis 9,-32705; lwz 5,0x8(1); addi 9,9,18256; lwz 6,0x4(29); addi 11,31,340; lwz 10,0x8(29); addi 4,1,96; lwz 0,0xc(29); mtcrf 128,30; stw 5,0x154(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32708; stw 6,0x4(11); addi 28,9,-26600; stw 10,0x8(11); stw 7,0x60(1); stw 8,0x64(1); stw 31,0x10(1); beq 25f; mr 3,29; li 5,8; bl _s801D6824_29; b 26f; 25:; stw 31,0x8(1); 26:; stw 28,0x14(1); addi 9,31,356; lwz 8,0x8(1); li 7,0; lwz 10,0xc(29); addi 30,31,244; lwz 0,0x4(29); lwz 11,0x8(29); stw 8,0x164(31); stw 10,0xc(9); stw 0,0x4(9); stw 11,0x8(9); 27:; stw 7,0x108(31); lis 3,-13004; ori 3,3,43996; bl _s801D6824_30; li 0,1; mr 3,30; stw 0,0xf0(31); bl _s801D6824_31; b 1b; 28:; li 3,0; 29:; lwz 0,0x7c(1); mtspr 8,0; lmw 28,0x68(1); addi 1,1,120"
extern "C" void _s801D6824_0();
extern "C" void _s801D6824_1();
extern "C" void _s801D6824_2();
extern "C" void _s801D6824_3();
extern "C" void _s801D6824_4();
extern "C" void _s801D6824_5();
extern "C" void _s801D6824_6();
extern "C" void _s801D6824_7();
extern "C" void _s801D6824_8();
extern "C" void _s801D6824_9();
extern "C" void _s801D6824_10();
extern "C" void _s801D6824_11();
extern "C" void _s801D6824_12();
extern "C" void _s801D6824_13();
extern "C" void _s801D6824_14();
extern "C" void _s801D6824_15();
extern "C" void _s801D6824_16();
extern "C" void _s801D6824_17();
extern "C" void _s801D6824_18();
extern "C" void _s801D6824_19();
extern "C" void _s801D6824_20();
extern "C" void _s801D6824_21();
extern "C" void _s801D6824_22();
extern "C" void _s801D6824_23();
extern "C" void _s801D6824_24();
extern "C" void _s801D6824_25();
extern "C" void _s801D6824_26();
extern "C" void _s801D6824_27();
extern "C" void _s801D6824_28();
extern "C" void _s801D6824_29();
extern "C" void _s801D6824_30();
extern "C" void _s801D6824_31();
extern "C" void f_801D6824() {}
