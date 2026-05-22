// 0x801C6D90 MMUTarget::LaunchLot(int) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; cmpwi 4,-1; beq 0f; addi 4,4,1; b 1f; 0:; lwz 9,0x98(31); addi 4,9,1; 1:; mr 3,31; bl _s801C6D90_0; li 0,0; mr 3,31; stw 0,0x8c(31); bl _s801C6D90_1; mr 3,31; bl _s801C6D90_2; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801C6D90_0();
extern "C" void _s801C6D90_1();
extern "C" void _s801C6D90_2();
extern "C" void f_801C6D90() {}
