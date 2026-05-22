// 0x80204438 InteractorModule::DirectInteractor::UpdatePlumbBob(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,3; li 5,0; lwz 4,0x70(31); addi 3,1,8; li 6,1; bl _s80204438_0; lwz 3,0x78(31); li 4,3; bl _s80204438_1; lwz 10,0x78(31); addi 9,1,8; lwz 8,0x8(1); lwz 0,0x4(9); addi 11,10,296; lwz 7,0x8(9); stw 8,0x128(10); stw 0,0x4(11); stw 7,0x8(11); lwz 3,0x78(31); lwz 4,0x0(31); bl _s80204438_2; lwz 9,0x78(31); addi 4,31,80; lwz 3,0x164(9); bl _s80204438_3; lwz 9,0x78(31); lwz 0,0x154(9); andi. 9,0,16; beq 0f; mr 3,31; bl _s80204438_4; cmpwi 3,0; beq 1f; lwz 3,0x78(31); li 4,0; bl _s80204438_5; b 1f; 0:; mr 3,31; bl _s80204438_6; cmpwi 3,0; bne 1f; lwz 3,0x78(31); li 4,1; bl _s80204438_7; 1:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s80204438_0();
extern "C" void _s80204438_1();
extern "C" void _s80204438_2();
extern "C" void _s80204438_3();
extern "C" void _s80204438_4();
extern "C" void _s80204438_5();
extern "C" void _s80204438_6();
extern "C" void _s80204438_7();
extern "C" void f_80204438() {}
