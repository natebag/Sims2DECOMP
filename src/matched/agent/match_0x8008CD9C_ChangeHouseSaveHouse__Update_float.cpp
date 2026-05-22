// 0x8008CD9C ChangeHouseSaveHouse::Update(float) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 3,7; bl _s8008CD9C_0; mr. 10,3; beq 1f; addi 0,10,-2; cmplwi 0,1; bgt 0f; lwz 3,0x8(31); li 4,1; bl _s8008CD9C_1; b 1f; 0:; cmpwi 10,1; bne 1f; lis 9,-32707; lis 11,-32696; lfs f1,0x7dac(9); mr 3,31; stw 10,0x5900(11); li 4,2; bl _s8008CD9C_2; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8008CD9C_0();
extern "C" void _s8008CD9C_1();
extern "C" void _s8008CD9C_2();
extern "C" void f_8008CD9C() {}
