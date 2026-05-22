// 0x8019E9F4 CASPersonalTarget::ParseDescriptionText(short, (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stw 31,0x24(1); stw 0,0x2c(1); mr 31,5; cmpwi 4,2; beq 4f; bgt 0f; cmpwi 4,0; beq 3f; cmpwi 4,1; beq 1f; b 8f; 0:; cmpwi 4,3; beq 2f; cmpwi 4,4; beq 5f; b 8f; 1:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12116; addi 3,1,8; crxor 6,6,6; bl _s8019E9F4_0; lwz 9,0x8(1); b 6f; 2:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12096; addi 3,1,12; crxor 6,6,6; bl _s8019E9F4_1; lwz 9,0xc(1); b 6f; 3:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12072; addi 3,1,16; crxor 6,6,6; bl _s8019E9F4_2; lwz 9,0x10(1); b 6f; 4:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12048; addi 3,1,20; crxor 6,6,6; bl _s8019E9F4_3; lwz 9,0x14(1); b 6f; 5:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12024; addi 3,1,24; crxor 6,6,6; bl _s8019E9F4_4; lwz 9,0x18(1); 6:; li 4,0; cmpwi 9,0; beq 7f; lwz 4,0x0(9); 7:; mr 3,31; bl _s8019E9F4_5; b 9f; 8:; lis 4,-32705; mr 3,31; addi 4,4,-17308; bl _s8019E9F4_6; 9:; lwz 0,0x2c(1); mtspr 8,0; lwz 31,0x24(1); addi 1,1,40"
extern "C" void _s8019E9F4_0();
extern "C" void _s8019E9F4_1();
extern "C" void _s8019E9F4_2();
extern "C" void _s8019E9F4_3();
extern "C" void _s8019E9F4_4();
extern "C" void _s8019E9F4_5();
extern "C" void _s8019E9F4_6();
extern "C" void f_8019E9F4() {}
