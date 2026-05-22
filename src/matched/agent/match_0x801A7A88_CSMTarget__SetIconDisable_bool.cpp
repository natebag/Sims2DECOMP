// 0x801A7A88 CSMTarget::SetIconDisable(bool) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stw 31,0x24(1); stw 0,0x2c(1); mr 31,3; lwz 0,0xd4(31); cmpw 4,0; beq 1f; stw 4,0xd4(31); addi 3,1,8; bl _s801A7A88_0; lwz 0,0x88(31); cmpwi 0,0; beq 0f; addi 3,1,8; bl _s801A7A88_1; lwz 5,0x8c(31); addi 3,1,8; lwz 4,-30592(13); bl _s801A7A88_2; lwz 4,0xd4(31); addi 3,1,8; bl _s801A7A88_3; lwz 4,-30588(13); addi 3,1,8; lwz 5,0x8c(31); bl _s801A7A88_4; lwz 4,0xd4(31); addi 3,1,8; bl _s801A7A88_5; addi 3,1,8; bl _s801A7A88_6; 0:; addi 3,1,8; li 4,2; bl _s801A7A88_7; 1:; lwz 0,0x2c(1); mtspr 8,0; lwz 31,0x24(1); addi 1,1,40"
extern "C" void _s801A7A88_0();
extern "C" void _s801A7A88_1();
extern "C" void _s801A7A88_2();
extern "C" void _s801A7A88_3();
extern "C" void _s801A7A88_4();
extern "C" void _s801A7A88_5();
extern "C" void _s801A7A88_6();
extern "C" void _s801A7A88_7();
extern "C" void f_801A7A88() {}
