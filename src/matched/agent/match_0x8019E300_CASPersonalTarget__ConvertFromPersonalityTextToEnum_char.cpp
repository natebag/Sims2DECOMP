// 0x8019E300 CASPersonalTarget::ConvertFromPersonalityTextToEnum(char (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; lis 3,-32705; addi 3,3,-12464; bl _s8019E300_0; cmpwi 3,0; li 3,0; beq 1f; lis 3,-32705; mr 4,31; addi 3,3,-12456; bl _s8019E300_1; cmpwi 3,0; li 3,1; beq 1f; lis 3,-32705; mr 4,31; addi 3,3,-12448; bl _s8019E300_2; cmpwi 3,0; li 3,2; beq 1f; lis 3,-32705; mr 4,31; addi 3,3,-12444; bl _s8019E300_3; cmpwi 3,0; li 3,3; beq 1f; lis 3,-32705; mr 4,31; addi 3,3,-12432; bl _s8019E300_4; cmpwi 3,0; li 3,4; beq 1f; lis 3,-32705; mr 4,31; addi 3,3,-12424; bl _s8019E300_5; cmpwi 3,0; li 3,5; beq 1f; lis 3,-32705; mr 4,31; addi 3,3,-12416; bl _s8019E300_6; cmpwi 3,0; li 3,6; beq 1f; lis 3,-32705; mr 4,31; addi 3,3,-12408; bl _s8019E300_7; cmpwi 3,0; li 3,7; beq 1f; lis 3,-32705; mr 4,31; addi 3,3,-12400; bl _s8019E300_8; cmpwi 3,0; beq 0f; lis 3,-32705; mr 4,31; addi 3,3,-12392; bl _s8019E300_9; cmpwi 3,0; li 3,9; beq 1f; li 3,5; b 1f; 0:; li 3,8; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8019E300_0();
extern "C" void _s8019E300_1();
extern "C" void _s8019E300_2();
extern "C" void _s8019E300_3();
extern "C" void _s8019E300_4();
extern "C" void _s8019E300_5();
extern "C" void _s8019E300_6();
extern "C" void _s8019E300_7();
extern "C" void _s8019E300_8();
extern "C" void _s8019E300_9();
extern "C" void f_8019E300() {}
