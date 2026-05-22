// 0x80260670 strnlen (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 4,0; mtspr 9,4; li 5,0; ble 2f; 0:; lbz 0,0x0(3); addi 3,3,1; extsb. 0,0; bne 1f; mr 3,5; blr; 1:; addi 5,5,1; bdnz 0b; 2:; mr 3,4"
extern "C" int f_80260670() {}
