// 0x8022F598 EIStaticSubModel::RebuildShaders(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 30,0; lwz 0,0x9c(31); cmpw 30,0; bge 1f; li 29,0; 0:; lwz 9,0x98(31); addi 30,30,1; add 9,29,9; lwz 3,0x4(9); addi 29,29,16; bl _s8022F598_0; lwz 0,0x9c(31); cmpw 30,0; blt 0b; 1:; li 30,0; stw 30,0x9c(31); bl _s8022F598_1; lwz 4,0x98(31); bl _s8022F598_2; lwz 9,0xa0(31); stw 30,0x98(31); cmpwi 9,0; beq 2f; lwz 9,0x40(9); lwz 0,0x7c(31); cmpw 0,9; bgt 2f; mr 3,31; bl _s8022F598_3; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8022F598_0();
extern "C" void _s8022F598_1();
extern "C" void _s8022F598_2();
extern "C" void _s8022F598_3();
extern "C" void f_8022F598() {}
