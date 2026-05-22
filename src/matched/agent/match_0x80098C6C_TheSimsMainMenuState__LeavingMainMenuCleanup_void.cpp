// 0x80098C6C TheSimsMainMenuState::LeavingMainMenuCleanup(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32697; li 0,1; addi 31,9,23428; lwz 11,0x68(31); stw 0,0xd8(31); cmpwi 11,0; beq 0f; lwz 9,0x80(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x68(31); 0:; lwz 11,0x54(31); cmpwi 11,0; beq 1f; lwz 9,0x80(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x54(31); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_80098C6C() {}
