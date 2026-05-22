// 0x800599D4 PlumbBob::StartupAll(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,-21420(13); cmpwi 0,0; bne 0f; li 3,508; bl _s800599D4_0; bl _s800599D4_1; stw 3,-21420(13); cmpwi 3,0; beq 0f; li 4,0; bl _s800599D4_2; 0:; lwz 0,-21416(13); cmpwi 0,0; bne 1f; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 1f; li 3,508; bl _s800599D4_3; bl _s800599D4_4; stw 3,-21416(13); cmpwi 3,0; beq 1f; li 4,1; bl _s800599D4_5; 1:; addi 31,13,-21420; addi 30,13,-21416; 2:; lwz 3,0x0(31); addi 31,31,4; cmpwi 3,0; beq 3f; bl _s800599D4_6; 3:; cmpw 31,30; ble 2b; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800599D4_0();
extern "C" void _s800599D4_1();
extern "C" void _s800599D4_2();
extern "C" void _s800599D4_3();
extern "C" void _s800599D4_4();
extern "C" void _s800599D4_5();
extern "C" void _s800599D4_6();
extern "C" void f_800599D4() {}
