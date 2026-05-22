// 0x801385B4 Room::GetPeopleCount(void) (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lwz 29,-21484(13); mr 26,3; li 27,0; li 30,0; lwz 9,0x0(29); lha 3,0x100(9); lwz 0,0x104(9); add 3,29,3; mtspr 8,0; blrl; mr 28,3; cmpw 27,28; bge 2f; 0:; lwz 9,0x0(29); mr 4,30; lwz 0,0xfc(9); lha 3,0xf8(9); mtspr 8,0; add 3,29,3; blrl; mr 31,3; lwz 9,0x4(31); lha 3,0x218(9); lwz 0,0x21c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; lwz 9,0x4(31); lwz 0,0x1a4(9); lha 3,0x1a0(9); mtspr 8,0; add 3,31,3; blrl; lhz 0,0x0(26); cmpw 3,0; bne 1f; addi 27,27,1; 1:; addi 30,30,1; cmpw 30,28; blt 0b; 2:; mr 3,27; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void f_801385B4() {}
