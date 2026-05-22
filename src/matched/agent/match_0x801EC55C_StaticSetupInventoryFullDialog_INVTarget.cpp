// 0x801EC55C StaticSetupInventoryFullDialog(INVTarget (824 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; mfcr 12; stmw 28,0x58(1); stw 0,0x6c(1); stw 12,0x54(1); mr 31,4; mr 30,5; cmpwi 3,0; bne 1f; 0:; li 3,0; b 17f; 1:; cmpwi 30,1; mfcr 29; beq 2f; cmpwi 30,2; beq 3f; b 0b; 2:; lis 9,-32704; addi 5,9,-28444; b 4f; 3:; lis 9,-32704; addi 5,9,-28420; 4:; lis 4,-32697; addi 3,1,32; addi 4,4,24012; crxor 6,6,6; bl _s801EC55C_0; lwz 9,0x20(1); addi 3,31,44; li 4,0; cmpwi 9,0; beq 5f; lwz 4,0x0(9); 5:; bl _s801EC55C_1; mtcrf 128,29; beq 6f; cmpwi 30,2; beq 7f; b 0b; 6:; lis 9,-32704; addi 5,9,-28396; b 8f; 7:; lis 9,-32704; addi 5,9,-28372; 8:; lis 30,-32697; addi 3,1,36; addi 4,30,24012; crxor 6,6,6; bl _s801EC55C_2; lwz 9,0x24(1); cmpwi 9,0; addi 3,31,40; li 4,0; beq 9f; lwz 4,0x0(9); 9:; bl _s801EC55C_3; lis 5,-32704; addi 4,30,24012; addi 3,1,40; addi 5,5,-28492; crxor 6,6,6; bl _s801EC55C_4; lwz 9,0x28(1); addi 3,31,48; li 4,0; cmpwi 9,0; beq 10f; lwz 4,0x0(9); 10:; bl _s801EC55C_5; addi 30,31,52; addi 3,1,8; addi 29,31,56; bl _s801EC55C_6; cmpwi 4,31,0; addi 28,1,44; addi 4,1,8; mr 3,30; bl _s801EC55C_7; addi 30,1,48; addi 3,1,8; li 4,2; bl _s801EC55C_8; addi 3,1,8; bl _s801EC55C_9; addi 4,1,8; mr 3,29; bl _s801EC55C_10; addi 3,1,8; li 4,2; bl _s801EC55C_11; lis 3,-32692; lis 4,-1383; li 6,0; ori 4,4,3490; li 5,0; addi 3,3,-17444; bl _s801EC55C_12; li 9,0; mr 0,3; stw 9,0x30(1); stw 0,0x3c(31); mr 4,28; stw 9,0x2c(1); mr 5,30; bl _s801EC55C_13; lis 11,-32704; lhz 10,0x2(30); lhz 0,0x2(28); addi 11,11,-28348; li 6,1; lwz 7,0x0(11); lwz 8,0x4(11); sth 0,0x4a(31); lis 9,-32708; sth 10,0x48(31); addi 4,1,56; stw 6,0x0(31); addi 30,9,-18720; stw 7,0x38(1); stw 8,0x3c(1); stw 31,0x18(1); beq cr4,11f; addi 3,1,16; li 5,8; bl _s801EC55C_14; b 12f; 11:; stw 31,0x10(1); 12:; lis 9,-32704; stw 30,0x1c(1); addi 9,9,-28340; lwz 4,0x10(1); addi 10,1,16; lwz 6,0x0(9); lwz 7,0x4(9); lwz 5,0xc(10); addi 8,31,80; lwz 9,0x4(10); lis 11,-32709; lwz 0,0x8(10); addi 30,11,14552; stw 4,0x50(31); addi 11,1,64; stw 5,0xc(8); stw 9,0x4(8); stw 0,0x8(8); stw 6,0x40(1); stw 7,0x44(1); stw 31,0x10(1); beq cr4,13f; mr 4,11; addi 3,1,8; li 5,8; bl _s801EC55C_15; b 14f; 13:; stw 31,0x8(1); 14:; stw 30,0x14(1); lis 9,-32704; addi 11,1,8; lwz 4,0x8(1); addi 9,9,-28456; lwz 5,0x4(11); lwz 6,0x8(11); addi 10,31,96; lwz 0,0xc(11); mr 30,11; lwz 7,0x0(9); lwz 8,0x4(9); stw 4,0x60(31); lis 9,-32709; stw 0,0xc(10); addi 29,9,14552; stw 5,0x4(10); addi 9,1,72; stw 6,0x8(10); stw 7,0x48(1); stw 8,0x4c(1); stw 31,0x10(1); beq cr4,15f; mr 4,9; mr 3,30; li 5,8; bl _s801EC55C_16; b 16f; 15:; stw 31,0x8(1); 16:; stw 29,0x14(1); addi 11,31,112; lwz 7,0x8(1); lis 9,-32704; lwz 8,0xc(30); addi 9,9,-28448; lwz 10,0x4(30); li 3,1; lwz 0,0x8(30); stw 7,0x70(31); stw 8,0xc(11); stw 10,0x4(11); stw 0,0x8(11); stw 9,0x80(31); 17:; lwz 0,0x6c(1); lwz 12,0x54(1); mtspr 8,0; lmw 28,0x58(1); mtcrf 8,12; addi 1,1,104"
extern "C" void _s801EC55C_0();
extern "C" void _s801EC55C_1();
extern "C" void _s801EC55C_2();
extern "C" void _s801EC55C_3();
extern "C" void _s801EC55C_4();
extern "C" void _s801EC55C_5();
extern "C" void _s801EC55C_6();
extern "C" void _s801EC55C_7();
extern "C" void _s801EC55C_8();
extern "C" void _s801EC55C_9();
extern "C" void _s801EC55C_10();
extern "C" void _s801EC55C_11();
extern "C" void _s801EC55C_12();
extern "C" void _s801EC55C_13();
extern "C" void _s801EC55C_14();
extern "C" void _s801EC55C_15();
extern "C" void _s801EC55C_16();
extern "C" void f_801EC55C() {}
