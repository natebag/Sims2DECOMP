// 0x800B82D4 Globs::Shutdown(void) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 3,-21492(13); cmpwi 3,0; beq 1f; bl _s800B82D4_0; lwz 3,-21492(13); cmpwi 3,0; beq 0f; li 4,3; bl _s800B82D4_1; 0:; li 0,0; stw 0,-21492(13); 1:; lwz 3,-21424(13); li 31,0; bl _s800B82D4_2; lwz 3,-21476(13); stw 31,-21424(13); bl _s800B82D4_3; lwz 11,-32056(13); stw 31,-21476(13); cmpwi 11,0; beq 2f; lwz 9,0xc(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 2:; lwz 3,-21508(13); stw 31,-32056(13); bl _s800B82D4_4; lwz 3,-21412(13); stw 31,-21508(13); cmpwi 3,0; beq 3f; bl _s800B82D4_5; stw 31,-21412(13); 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800B82D4_0();
extern "C" void _s800B82D4_1();
extern "C" void _s800B82D4_2();
extern "C" void _s800B82D4_3();
extern "C" void _s800B82D4_4();
extern "C" void _s800B82D4_5();
extern "C" void f_800B82D4() {}
