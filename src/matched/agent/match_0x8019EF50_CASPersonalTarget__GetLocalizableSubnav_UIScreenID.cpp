// 0x8019EF50 CASPersonalTarget::GetLocalizableSubnav(UIScreenID, (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stw 31,0x24(1); stw 0,0x2c(1); mr 31,6; cmpwi 4,20; bne 9f; cmpwi 5,2; beq 4f; bgt 0f; cmpwi 5,0; beq 3f; cmpwi 5,1; beq 1f; b 9f; 0:; cmpwi 5,3; beq 2f; cmpwi 5,4; beq 7f; b 9f; 1:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11784; addi 3,1,8; crxor 6,6,6; bl _s8019EF50_0; lwz 9,0x8(1); b 5f; 2:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11768; addi 3,1,12; crxor 6,6,6; bl _s8019EF50_1; lwz 9,0xc(1); b 5f; 3:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11748; addi 3,1,16; crxor 6,6,6; bl _s8019EF50_2; lwz 9,0x10(1); b 5f; 4:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11732; addi 3,1,20; crxor 6,6,6; bl _s8019EF50_3; lwz 9,0x14(1); 5:; li 4,0; cmpwi 9,0; beq 6f; lwz 4,0x0(9); 6:; mr 3,31; bl _s8019EF50_4; b 9f; 7:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11712; addi 3,1,24; crxor 6,6,6; bl _s8019EF50_5; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 8f; lwz 4,0x0(9); 8:; mr 3,31; bl _s8019EF50_6; 9:; lwz 0,0x2c(1); mtspr 8,0; lwz 31,0x24(1); addi 1,1,40"
extern "C" void _s8019EF50_0();
extern "C" void _s8019EF50_1();
extern "C" void _s8019EF50_2();
extern "C" void _s8019EF50_3();
extern "C" void _s8019EF50_4();
extern "C" void _s8019EF50_5();
extern "C" void _s8019EF50_6();
extern "C" void f_8019EF50() {}
