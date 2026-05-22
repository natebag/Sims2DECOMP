// 0x8018237C WidgetScreenFormat::LaunchWidgetScreenLayout(char (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 29,4; lwz 0,0x10(31); mr 30,5; mr 28,6; cmpwi 0,0; beq 0f; bl _s8018237C_0; lwz 4,0x10(31); bl _s8018237C_1; 0:; stw 30,0x1c(31); mr 4,29; li 5,2; mr 3,31; bl _s8018237C_2; bl _s8018237C_3; lwz 4,0xc(31); li 5,0; addi 4,4,1; bl _s8018237C_4; stw 3,0x14(31); mr 4,29; stw 3,0x10(31); li 5,3; mr 3,31; bl _s8018237C_5; addi 0,28,48; lwz 9,0x10(31); rlwinm 0,0,8,0,23; lwz 3,-25136(13); lis 4,-32705; lis 8,-32705; sth 0,0x8(1); li 6,0; li 7,3; addi 10,1,8; addi 4,4,-24068; addi 8,8,-24060; li 5,0; crxor 6,6,6; bl _s8018237C_6; bl _s8018237C_7; lwz 4,0x10(31); bl _s8018237C_8; li 0,0; stw 0,0x10(31); lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8018237C_0();
extern "C" void _s8018237C_1();
extern "C" void _s8018237C_2();
extern "C" void _s8018237C_3();
extern "C" void _s8018237C_4();
extern "C" void _s8018237C_5();
extern "C" void _s8018237C_6();
extern "C" void _s8018237C_7();
extern "C" void _s8018237C_8();
extern "C" void f_8018237C() {}
