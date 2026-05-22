// 0x80011D50 AptViewer::GetPlayersController(int) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; lwz 3,-26524(13); li 30,0; bl _s80011D50_0; cmpwi 3,0; beq 0f; lwz 30,-26524(13); mr 4,31; mr 3,30; bl _s80011D50_1; mr 4,3; mr 3,30; b 1f; 0:; lwz 3,-26524(13); bl _s80011D50_2; mr 4,3; cmpwi 4,-1; beq 2f; lwz 3,-26524(13); 1:; bl _s80011D50_3; mr 30,3; 2:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80011D50_0();
extern "C" void _s80011D50_1();
extern "C" void _s80011D50_2();
extern "C" void _s80011D50_3();
extern "C" void f_80011D50() {}
