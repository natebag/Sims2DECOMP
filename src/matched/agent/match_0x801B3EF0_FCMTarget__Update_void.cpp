// 0x801B3EF0 FCMTarget::Update(void) (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x84(31); cmpwi 0,0; beq 2f; lwz 0,0x8c(31); cmpwi 0,0; bne 2f; lwz 0,0x90(31); cmpwi 0,0; beq 0f; lwz 0,0x88(31); cmpwi 0,0; bne 2f; addi 30,31,168; lis 4,-32705; lis 7,-32705; li 5,250; addi 7,7,2196; li 6,0; li 8,0; addi 4,4,2236; mr 3,30; bl _s801B3EF0_0; mr 3,30; li 4,0; bl _s801B3EF0_1; mr 3,30; li 4,255; bl _s801B3EF0_2; mr 3,30; bl _s801B3EF0_3; li 0,1; stw 0,0x88(31); b 1f; 0:; lwz 0,0x88(31); cmpwi 0,0; beq 2f; addi 30,31,168; lis 4,-32705; lis 7,-32705; li 5,250; addi 7,7,2216; li 6,0; li 8,0; addi 4,4,2236; mr 3,30; bl _s801B3EF0_4; mr 3,30; li 4,64; bl _s801B3EF0_5; mr 3,30; li 4,0; bl _s801B3EF0_6; mr 3,30; bl _s801B3EF0_7; li 0,1; 1:; stw 0,0x8c(31); 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801B3EF0_0();
extern "C" void _s801B3EF0_1();
extern "C" void _s801B3EF0_2();
extern "C" void _s801B3EF0_3();
extern "C" void _s801B3EF0_4();
extern "C" void _s801B3EF0_5();
extern "C" void _s801B3EF0_6();
extern "C" void _s801B3EF0_7();
extern "C" void f_801B3EF0() {}
