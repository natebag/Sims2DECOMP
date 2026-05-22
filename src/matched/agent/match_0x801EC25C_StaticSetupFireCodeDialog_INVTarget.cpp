// 0x801EC25C StaticSetupFireCodeDialog(INVTarget (768 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; mfcr 12; stmw 24,0x78(1); stw 0,0x9c(1); stw 12,0x74(1); mr. 25,3; mr 31,4; mr 24,5; mcrf cr4,cr0; bne cr4,0f; li 3,0; b 8f; 0:; lis 30,-32697; lis 5,-32704; addi 3,1,64; addi 4,30,24012; addi 5,5,-28536; crxor 6,6,6; bl _s801EC25C_0; lwz 9,0x40(1); addi 3,31,44; li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; bl _s801EC25C_1; lis 4,-32704; addi 5,24,1; addi 4,4,-28512; addi 3,1,8; crxor 6,6,6; bl _s801EC25C_2; lis 4,-32697; addi 3,1,68; addi 4,4,24012; addi 5,1,8; crxor 6,6,6; bl _s801EC25C_3; lwz 9,0x44(1); cmpwi 9,0; addi 3,31,40; li 4,0; beq 2f; lwz 4,0x0(9); 2:; bl _s801EC25C_4; lis 5,-32704; addi 4,30,24012; addi 3,1,72; addi 5,5,-28492; crxor 6,6,6; bl _s801EC25C_5; lwz 9,0x48(1); addi 3,31,48; li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; bl _s801EC25C_6; addi 29,31,56; addi 30,1,40; mr 3,30; mr 26,30; bl _s801EC25C_7; mr 4,30; addi 3,31,52; bl _s801EC25C_8; li 4,2; mr 3,30; bl _s801EC25C_9; addi 28,1,76; addi 27,1,80; mr 3,30; bl _s801EC25C_10; mr 4,30; mr 3,29; bl _s801EC25C_11; mr 3,30; li 4,2; bl _s801EC25C_12; lis 9,-32704; rlwinm 0,24,2,0,29; addi 9,9,-28488; lis 3,-32692; lwzx 4,9,0; li 6,0; li 5,0; addi 3,3,-17444; bl _s801EC25C_13; li 9,0; mr 0,3; stw 9,0x50(1); stw 0,0x3c(31); mr 4,28; stw 9,0x4c(1); mr 5,27; bl _s801EC25C_14; lis 9,-32704; lhz 10,0x2(28); lhz 8,0x2(27); addi 9,9,-28472; lwz 11,0x0(9); lwz 12,0x4(9); li 0,1; sth 10,0x4a(31); lis 30,-32708; sth 8,0x48(31); addi 30,30,-18960; stw 0,0x0(31); addi 4,1,88; stw 11,0x58(1); stw 12,0x5c(1); li 5,8; addi 3,1,48; stw 25,0x38(1); bl _s801EC25C_15; lis 9,-32704; stw 30,0x3c(1); addi 9,9,-28464; lwz 5,0x30(1); addi 10,1,48; lwz 6,0x0(9); lwz 7,0x4(9); lwz 4,0xc(10); addi 8,31,80; lwz 9,0x4(10); lis 11,-32708; lwz 0,0x8(10); addi 3,1,96; stw 5,0x50(31); addi 30,11,-18840; stw 4,0xc(8); stw 9,0x4(8); stw 0,0x8(8); stw 6,0x60(1); stw 7,0x64(1); stw 25,0x30(1); beq cr4,4f; mr 4,3; li 5,8; addi 3,1,40; bl _s801EC25C_16; b 5f; 4:; stw 25,0x28(1); 5:; stw 30,0x34(1); lis 9,-32704; lwz 6,0x28(1); addi 9,9,-28456; lwz 5,0x8(26); addi 11,31,96; lwz 10,0x4(26); addi 4,1,104; lwz 0,0xc(26); cmpwi 31,0; stw 6,0x60(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32709; stw 10,0x4(11); addi 30,9,14552; stw 5,0x8(11); stw 7,0x68(1); stw 8,0x6c(1); stw 31,0x30(1); beq 6f; mr 3,26; li 5,8; bl _s801EC25C_17; b 7f; 6:; stw 31,0x28(1); 7:; stw 30,0x34(1); addi 11,31,112; lwz 7,0x28(1); lis 9,-32704; lwz 8,0xc(26); addi 9,9,-28448; lwz 10,0x4(26); li 3,1; lwz 0,0x8(26); stw 7,0x70(31); stw 8,0xc(11); stw 10,0x4(11); stw 0,0x8(11); stw 9,0x80(31); 8:; lwz 0,0x9c(1); lwz 12,0x74(1); mtspr 8,0; lmw 24,0x78(1); mtcrf 8,12; addi 1,1,152"
extern "C" void _s801EC25C_0();
extern "C" void _s801EC25C_1();
extern "C" void _s801EC25C_2();
extern "C" void _s801EC25C_3();
extern "C" void _s801EC25C_4();
extern "C" void _s801EC25C_5();
extern "C" void _s801EC25C_6();
extern "C" void _s801EC25C_7();
extern "C" void _s801EC25C_8();
extern "C" void _s801EC25C_9();
extern "C" void _s801EC25C_10();
extern "C" void _s801EC25C_11();
extern "C" void _s801EC25C_12();
extern "C" void _s801EC25C_13();
extern "C" void _s801EC25C_14();
extern "C" void _s801EC25C_15();
extern "C" void _s801EC25C_16();
extern "C" void _s801EC25C_17();
extern "C" void f_801EC25C() {}
