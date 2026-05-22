// 0x800986A0 TheSimsMainMenuState::Shutdown(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 11,-32697; li 0,-1; lwz 10,0x5e80(11); lis 9,-32697; addi 31,9,23428; stw 0,0x3ac(10); lwz 11,0x68(31); cmpwi 11,0; beq 0f; lwz 9,0x80(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x68(31); 0:; lwz 3,-24620(13); cmpwi 3,0; beq 1f; li 4,3; bl _s800986A0_0; li 0,0; stw 0,-24620(13); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800986A0_0();
extern "C" void f_800986A0() {}
