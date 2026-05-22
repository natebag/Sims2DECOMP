// 0x8033815C ERSampledata::~ERSampledata(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lis 9,-32697; addi 9,9,-13952; mr 29,4; lis 3,-32692; stw 9,0x0(31); addi 3,3,14816; mr 4,31; bl _s8033815C_0; li 30,0; lwz 3,0x14(31); bl _s8033815C_1; lwz 3,0x18(31); stw 30,0x14(31); cmpwi 3,0; beq 0f; bl _s8033815C_2; stw 30,0x18(31); 0:; mr 3,31; li 4,0; bl _s8033815C_3; andi. 0,29,1; beq 1f; lwz 3,-22572(13); mr 4,31; bl _s8033815C_4; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8033815C_0();
extern "C" void _s8033815C_1();
extern "C" void _s8033815C_2();
extern "C" void _s8033815C_3();
extern "C" void _s8033815C_4();
extern "C" void f_8033815C() {}
