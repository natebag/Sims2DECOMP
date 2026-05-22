// 0x801D94E8 PRGTarget::GetTotalPromotions(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 11,-21476(13); lis 9,-32697; lwz 4,0x5c5c(9); li 29,0; lwz 9,0x0(11); li 30,0; lha 3,0x120(9); lwz 0,0x124(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; 0:; lwz 9,0x0(31); addi 4,30,11; lha 3,0x150(9); lwz 0,0x154(9); add 3,31,3; mtspr 8,0; blrl; add 29,29,3; cmpwi 29,90; ble 1f; li 29,90; 1:; addi 30,30,1; cmpwi 30,9; ble 0b; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_801D94E8() {}
