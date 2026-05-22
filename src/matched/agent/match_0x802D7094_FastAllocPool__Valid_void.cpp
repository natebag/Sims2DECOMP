// 0x802D7094 FastAllocPool::Valid(void) (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 11,0x4(3); cmpwi 11,0; beq 2f; lwz 10,0x0(3); li 31,0; cmplw 11,10; blt 0f; lwz 0,0xc(3); lwz 9,0x8(3); mullw 0,0,9; add 0,10,0; subfc 31,0,11; subfe 31,31,31; neg 31,31; 0:; cmpwi 31,0; bne 2f; bl _s802D7094_0; cmpwi 3,0; beq 1f; stw 31,0x0(31); 1:; .long 0x00000001; li 3,0; b 8f; 2:; lwz 9,0x4(3); cmpwi 9,0; beq 7f; 3:; lwz 0,0x4(9); mr 11,0; cmpwi 0,0; beq 6f; lwz 10,0x0(3); li 31,0; cmplw 11,10; blt 4f; lwz 0,0xc(3); lwz 9,0x8(3); mullw 0,0,9; add 0,10,0; subfc 31,0,11; subfe 31,31,31; neg 31,31; 4:; cmpwi 31,0; bne 6f; bl _s802D7094_1; cmpwi 3,0; beq 5f; stw 31,0x0(31); 5:; .long 0x00000001; li 3,0; b 8f; 6:; mr. 9,11; bne 3b; 7:; li 3,1; 8:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802D7094_0();
extern "C" void _s802D7094_1();
extern "C" void f_802D7094() {}
