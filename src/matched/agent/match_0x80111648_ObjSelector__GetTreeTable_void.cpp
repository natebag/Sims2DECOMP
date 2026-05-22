// 0x80111648 ObjSelector::GetTreeTable(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x3c(31); cmpwi 0,0; bne 0f; lwz 3,0x50(31); mr 4,31; lwz 9,0x0(3); lha 0,0x158(9); lwz 9,0x15c(9); add 3,3,0; mtspr 8,9; blrl; 0:; lwz 3,0x3c(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_80111648() {}
