// 0x801D6370 PCTTarget::start_action_menu(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0xe4(3); cmpwi 0,0; beq 0f; lis 9,-32697; lwz 5,0x84(3); lwz 4,0x5bc8(9); mr 3,0; bl _s801D6370_0; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801D6370_0();
extern "C" void f_801D6370() {}
