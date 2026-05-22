// 0x8005950C Player::Reset(int) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x8(31); stw 4,0x0(31); cmpwi 0,0; bne 0f; li 3,16; bl _s8005950C_0; lwz 4,0x0(31); bl _s8005950C_1; stw 3,0x8(31); 0:; lwz 0,0xc(31); cmpwi 0,0; bne 1f; bl _s8005950C_2; li 6,0; li 7,0; li 4,1392; li 5,16; bl _s8005950C_3; mr 30,3; li 4,0; li 5,1392; bl _s8005950C_4; lwz 4,0x0(31); mr 3,30; bl _s8005950C_5; cmpwi 3,0; stw 3,0xc(31); beq 2f; 1:; lwz 3,0xc(31); bl _s8005950C_6; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8005950C_0();
extern "C" void _s8005950C_1();
extern "C" void _s8005950C_2();
extern "C" void _s8005950C_3();
extern "C" void _s8005950C_4();
extern "C" void _s8005950C_5();
extern "C" void _s8005950C_6();
extern "C" void f_8005950C() {}
