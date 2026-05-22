// 0x801C2F6C M2MTarget::PopButtonFilters(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 4,0x170(31); cmpwi 4,0; beq 0f; li 3,0; bl _s801C2F6C_0; li 0,0; stw 0,0x170(31); 0:; lwz 4,0x174(31); cmpwi 4,0; beq 1f; li 3,1; bl _s801C2F6C_1; li 0,0; stw 0,0x174(31); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801C2F6C_0();
extern "C" void _s801C2F6C_1();
extern "C" void f_801C2F6C() {}
