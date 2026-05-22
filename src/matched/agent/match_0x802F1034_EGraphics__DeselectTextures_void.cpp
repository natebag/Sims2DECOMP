// 0x802F1034 EGraphics::DeselectTextures(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; li 4,0; lwz 9,0x0(29); li 30,0; lha 3,0x80(9); lwz 0,0x84(9); add 3,29,3; mtspr 8,0; blrl; mr 31,3; 0:; lwz 9,0x70(31); mr 5,30; li 4,0; addi 30,30,1; lha 3,0x120(9); lwz 0,0x124(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 30,1; ble 0b; lwz 9,0x0(29); mr 4,31; lha 3,0x88(9); lwz 0,0x8c(9); add 3,29,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_802F1034() {}
