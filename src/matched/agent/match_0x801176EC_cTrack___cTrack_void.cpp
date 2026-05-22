// 0x801176EC cTrack::~cTrack(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,9032; mr 30,4; stw 9,0x94(31); bl _s801176EC_0; lwz 3,0x50(31); cmpwi 3,0; beq 1f; bl _s801176EC_1; lwz 3,0x50(31); cmpwi 3,0; beq 0f; li 4,3; bl _s801176EC_2; 0:; li 0,0; stw 0,0x50(31); 1:; lwz 9,-24136(13); mr 4,31; lwz 3,0x50(9); bl _s801176EC_3; lwz 3,0x0(31); cmpwi 3,0; beq 2f; bl _s801176EC_4; li 0,0; stw 0,0x0(31); 2:; addi 3,31,44; li 4,2; bl _s801176EC_5; addi 3,31,36; li 4,2; bl _s801176EC_6; addi 3,31,28; li 4,2; bl _s801176EC_7; andi. 0,30,1; beq 3f; mr 3,31; bl _s801176EC_8; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801176EC_0();
extern "C" void _s801176EC_1();
extern "C" void _s801176EC_2();
extern "C" void _s801176EC_3();
extern "C" void _s801176EC_4();
extern "C" void _s801176EC_5();
extern "C" void _s801176EC_6();
extern "C" void _s801176EC_7();
extern "C" void _s801176EC_8();
extern "C" void f_801176EC() {}
