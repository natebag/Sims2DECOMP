// 0x80327534 EResourceManager::CalcId(char (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr. 31,3; li 3,0; beq 0f; lis 4,-32702; mr 3,31; addi 4,4,4076; bl _s80327534_0; cmpwi 3,0; li 3,0; beq 0f; mr 3,31; li 4,0; bl _s80327534_1; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80327534_0();
extern "C" void _s80327534_1();
extern "C" void f_80327534() {}
