// 0x8002BCB4 EIWallPart::~EIWallPart(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32698; lwz 3,0x3ac(31); addi 9,9,-20160; mr 30,4; stw 9,0x0(31); cmpwi 3,0; beq 0f; bl _s8002BCB4_0; li 0,0; stw 0,0x3ac(31); 0:; lwz 3,0x4(31); cmpwi 3,0; beq 1f; mr 4,31; bl _s8002BCB4_1; 1:; lwz 3,0x3a0(31); cmpwi 3,0; beq 2f; bl _s8002BCB4_2; li 0,0; stw 0,0x3a0(31); 2:; addi 3,31,808; li 4,2; bl _s8002BCB4_3; mr 3,31; li 4,0; bl _s8002BCB4_4; andi. 0,30,1; beq 3f; mr 3,31; bl _s8002BCB4_5; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8002BCB4_0();
extern "C" void _s8002BCB4_1();
extern "C" void _s8002BCB4_2();
extern "C" void _s8002BCB4_3();
extern "C" void _s8002BCB4_4();
extern "C" void _s8002BCB4_5();
extern "C" void f_8002BCB4() {}
