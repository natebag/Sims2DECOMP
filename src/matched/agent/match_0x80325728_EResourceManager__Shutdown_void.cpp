// 0x80325728 EResourceManager::Shutdown(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; addi 3,31,3336; bl _s80325728_0; addi 3,31,68; bl _s80325728_1; lwz 11,-22652(13); cmpwi 11,0; beq 0f; lwz 9,0x0(11); mr 4,31; lha 3,0x48(9); lwz 0,0x4c(9); add 3,11,3; mtspr 8,0; blrl; 0:; mr 3,31; bl _s80325728_2; li 0,0; stw 0,0x48(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80325728_0();
extern "C" void _s80325728_1();
extern "C" void _s80325728_2();
extern "C" void f_80325728() {}
