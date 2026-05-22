// 0x802D2D78 EString::Compare(char (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,0x0(3); lbz 0,0x0(3); cmpwi 0,0; bne 2f; cmpwi 4,0; beq 0f; lbz 0,0x0(4); cmpwi 0,0; bne 1f; 0:; li 3,0; b 5f; 1:; li 3,-1; b 5f; 2:; cmpwi 4,0; beq 3f; lbz 0,0x0(4); cmpwi 0,0; bne 4f; 3:; li 3,1; b 5f; 4:; bl _s802D2D78_0; 5:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802D2D78_0();
extern "C" void f_802D2D78() {}
