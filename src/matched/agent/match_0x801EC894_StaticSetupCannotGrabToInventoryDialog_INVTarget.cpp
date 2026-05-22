// 0x801EC894 StaticSetupCannotGrabToInventoryDialog(INVTarget (768 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; mfcr 12; stmw 27,0x54(1); stw 0,0x6c(1); stw 12,0x50(1); mr. 27,3; mr 31,4; mcrf cr4,cr0; bne cr4,0f; li 3,0; b 9f; 0:; lis 29,-32697; lis 5,-32704; addi 3,1,32; addi 4,29,24012; addi 5,5,-28332; lis 30,-32697; crxor 6,6,6; bl _s801EC894_0; lwz 9,0x20(1); addi 3,31,44; li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; bl _s801EC894_1; lis 5,-32704; addi 3,1,36; addi 4,30,24012; addi 5,5,-28304; crxor 6,6,6; bl _s801EC894_2; lwz 9,0x24(1); addi 3,31,40; li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; bl _s801EC894_3; lis 5,-32704; addi 4,30,24012; addi 3,1,40; addi 5,5,-28276; crxor 6,6,6; bl _s801EC894_4; lwz 9,0x28(1); addi 3,31,48; li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; bl _s801EC894_5; lis 5,-32704; addi 4,29,24012; addi 3,1,44; addi 5,5,-28272; crxor 6,6,6; bl _s801EC894_6; lwz 9,0x2c(1); addi 3,31,52; li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; bl _s801EC894_7; addi 30,31,56; addi 29,1,48; addi 3,1,8; bl _s801EC894_8; addi 28,1,52; addi 4,1,8; mr 3,30; bl _s801EC894_9; addi 3,1,8; li 4,2; bl _s801EC894_10; lis 3,-32692; lis 4,-1383; li 6,0; ori 4,4,3490; li 5,0; addi 3,3,-17444; bl _s801EC894_11; li 9,0; mr 0,3; stw 9,0x34(1); stw 0,0x3c(31); mr 4,29; stw 9,0x30(1); mr 5,28; bl _s801EC894_12; lis 9,-32704; lhz 10,0x2(29); lhz 8,0x2(28); addi 9,9,-28268; lwz 11,0x0(9); lwz 12,0x4(9); li 0,2; sth 10,0x4a(31); lis 30,-32708; sth 8,0x48(31); addi 30,30,-18960; stw 0,0x0(31); addi 4,1,56; stw 11,0x38(1); stw 12,0x3c(1); li 5,8; addi 3,1,16; stw 27,0x18(1); bl _s801EC894_13; lis 9,-32704; stw 30,0x1c(1); addi 9,9,-28260; lwz 5,0x10(1); addi 10,1,16; lwz 6,0x0(9); lwz 7,0x4(9); lwz 4,0xc(10); addi 8,31,80; lwz 9,0x4(10); lis 11,-32708; lwz 0,0x8(10); addi 3,1,64; stw 5,0x50(31); addi 30,11,-18840; stw 4,0xc(8); stw 9,0x4(8); stw 0,0x8(8); stw 6,0x40(1); stw 7,0x44(1); stw 27,0x10(1); beq cr4,5f; mr 4,3; li 5,8; addi 3,1,8; bl _s801EC894_14; b 6f; 5:; stw 27,0x8(1); 6:; stw 30,0x14(1); lis 9,-32704; addi 11,1,8; lwz 5,0x8(1); addi 9,9,-28456; lwz 4,0x4(11); lwz 6,0x8(11); addi 10,31,96; lwz 0,0xc(11); mr 30,11; lwz 7,0x0(9); lwz 8,0x4(9); cmpwi 31,0; stw 5,0x60(31); lis 9,-32709; stw 0,0xc(10); addi 29,9,14552; stw 4,0x4(10); addi 9,1,72; stw 6,0x8(10); stw 7,0x48(1); stw 8,0x4c(1); stw 31,0x10(1); beq 7f; mr 4,9; mr 3,30; li 5,8; bl _s801EC894_15; b 8f; 7:; stw 31,0x8(1); 8:; stw 29,0x14(1); addi 11,31,112; lwz 7,0x8(1); lis 9,-32704; lwz 8,0xc(30); addi 9,9,-28448; lwz 10,0x4(30); li 6,0; lwz 0,0x8(30); li 3,1; stw 7,0x70(31); stw 8,0xc(11); stw 10,0x4(11); stw 0,0x8(11); stw 9,0x80(31); stw 6,0x14(31); 9:; lwz 0,0x6c(1); lwz 12,0x50(1); mtspr 8,0; lmw 27,0x54(1); mtcrf 8,12; addi 1,1,104"
extern "C" void _s801EC894_0();
extern "C" void _s801EC894_1();
extern "C" void _s801EC894_2();
extern "C" void _s801EC894_3();
extern "C" void _s801EC894_4();
extern "C" void _s801EC894_5();
extern "C" void _s801EC894_6();
extern "C" void _s801EC894_7();
extern "C" void _s801EC894_8();
extern "C" void _s801EC894_9();
extern "C" void _s801EC894_10();
extern "C" void _s801EC894_11();
extern "C" void _s801EC894_12();
extern "C" void _s801EC894_13();
extern "C" void _s801EC894_14();
extern "C" void _s801EC894_15();
extern "C" void f_801EC894() {}
