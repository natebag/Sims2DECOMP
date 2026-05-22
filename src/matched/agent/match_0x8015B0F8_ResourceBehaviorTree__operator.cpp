// 0x8015B0F8 ResourceBehaviorTree::operator (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; cmpwi 31,104; bne 0f; lis 9,-32696; addi 11,9,29888; lwz 3,0x4(11); cmpwi 3,0; beq 0f; lwz 9,0x4(3); lis 0,17477; ori 0,0,21333; stw 9,0x4(11); stw 0,0x0(3); bne 1f; 0:; bl _s8015B0F8_0; mr 4,31; li 5,0; bl _s8015B0F8_1; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8015B0F8_0();
extern "C" void _s8015B0F8_1();
extern "C" void f_8015B0F8() {}
