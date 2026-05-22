// 0x80005FFC PlayerCheats::CreateBtnMask(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,6; addi 3,3,28; mtspr 9,0; li 9,0; 0:; lhz 0,0x0(3); addi 3,3,2; or 9,0,9; bdnz 0b; mr 3,9"
extern "C" int f_80005FFC() {}
