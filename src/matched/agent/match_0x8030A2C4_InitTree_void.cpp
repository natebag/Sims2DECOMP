// 0x8030A2C4 InitTree(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 11,256; lwz 9,-22664(13); mtspr 9,11; li 0,4096; addi 9,9,8194; 0:; sth 0,0x0(9); addi 9,9,2; bdnz 0b; li 11,4096; lwz 9,-22660(13); mtspr 9,11; li 0,4096; addi 9,9,8190; 1:; sth 0,0x0(9); addi 9,9,-2; bdnz 1b"
extern "C" void f_8030A2C4() {}
