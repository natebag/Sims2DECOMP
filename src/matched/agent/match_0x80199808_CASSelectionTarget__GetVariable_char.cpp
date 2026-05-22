// 0x80199808 CASSelectionTarget::GetVariable(char (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; li 3,32; bl _s80199808_0; mr 31,3; li 0,0; lis 3,-32705; stb 0,0x0(31); addi 3,3,-14736; mr 4,30; bl _s80199808_1; cmpwi 3,0; bne 0f; mr 3,29; mr 4,31; bl _s80199808_2; b 1f; 0:; lis 3,-32705; mr 4,30; addi 3,3,-14712; bl _s80199808_3; mr 30,3; cmpwi 30,0; bne 1f; addi 4,29,1496; mr 3,31; li 5,3; bl _s80199808_4; stb 30,0x2(31); 1:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80199808_0();
extern "C" void _s80199808_1();
extern "C" void _s80199808_2();
extern "C" void _s80199808_3();
extern "C" void _s80199808_4();
extern "C" void f_80199808() {}
