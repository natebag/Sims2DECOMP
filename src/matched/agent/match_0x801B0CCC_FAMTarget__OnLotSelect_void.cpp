// 0x801B0CCC FAMTarget::OnLotSelect(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s801B0CCC_0; cmpwi 3,0; beq 0f; mr 3,31; li 4,1; bl _s801B0CCC_1; b 1f; 0:; mr 3,31; li 4,2; bl _s801B0CCC_2; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801B0CCC_0();
extern "C" void _s801B0CCC_1();
extern "C" void _s801B0CCC_2();
extern "C" void f_801B0CCC() {}
