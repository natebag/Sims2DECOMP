// 0x80281BD4 AptActionInterpreter::~AptActionInterpreter(void) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; addi 9,31,36; lwz 4,0x8(9); cmpwi 4,0; beq 0f; lwz 5,0x4(9); lwz 3,-23020(13); rlwinm 5,5,2,0,29; bl _s80281BD4_0; 0:; addi 9,31,24; lwz 4,0x8(9); cmpwi 4,0; beq 1f; lwz 5,0x4(9); lwz 3,-23020(13); rlwinm 5,5,2,0,29; bl _s80281BD4_1; 1:; addi 9,31,12; lwz 4,0x8(9); cmpwi 4,0; beq 2f; lwz 5,0x4(9); lwz 3,-23020(13); rlwinm 5,5,2,0,29; bl _s80281BD4_2; 2:; lwz 4,0x8(31); cmpwi 4,0; beq 3f; lwz 5,0x4(31); lwz 3,-23020(13); rlwinm 5,5,2,0,29; bl _s80281BD4_3; 3:; andi. 0,30,1; beq 4f; mr 3,31; bl _s80281BD4_4; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80281BD4_0();
extern "C" void _s80281BD4_1();
extern "C" void _s80281BD4_2();
extern "C" void _s80281BD4_3();
extern "C" void _s80281BD4_4();
extern "C" void f_80281BD4() {}
