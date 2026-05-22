// 0x8008CFD4 ChangeHouseLoadHouse::Reset(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,-24508(13); mr 31,3; cmpwi 9,0; beq 0f; addi 3,9,48; li 4,32; bl _s8008CFD4_0; lwz 3,-24508(13); li 4,32; addi 3,3,48; bl _s8008CFD4_1; 0:; lwz 3,-21492(13); li 4,3; bl _s8008CFD4_2; bl _s8008CFD4_3; li 0,0; lis 3,-32697; stw 0,0xc(31); addi 3,3,23428; stw 0,0x1c(31); li 4,0; li 5,25; bl _s8008CFD4_4; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8008CFD4_0();
extern "C" void _s8008CFD4_1();
extern "C" void _s8008CFD4_2();
extern "C" void _s8008CFD4_3();
extern "C" void _s8008CFD4_4();
extern "C" void f_8008CFD4() {}
