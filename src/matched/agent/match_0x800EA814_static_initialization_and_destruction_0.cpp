// 0x800EA814 __static_initialization_and_destruction_0 (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; addi 3,13,-24272; bl _s800EA814_0; lis 11,-32696; li 0,0; addi 9,11,25436; stw 0,0x635c(11); addi 10,9,12; addi 11,9,4; stw 0,0x4(10); stw 0,0x4(11); stw 0,0x4(9); b 1f; 0:; lis 3,-32696; li 4,2; addi 3,3,25436; bl _s800EA814_1; addi 3,13,-24272; li 4,2; bl _s800EA814_2; 1:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s800EA814_0();
extern "C" void _s800EA814_1();
extern "C" void _s800EA814_2();
extern "C" void f_800EA814() {}
