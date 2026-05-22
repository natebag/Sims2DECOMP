// 0x802D0A5C EAHeap::Init(void (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 4,4; beq 0f; cmpwi 5,0; beq 0f; li 6,0; li 7,0; li 8,0; li 9,0; bl _s802D0A5C_0; b 1f; 0:; li 3,1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802D0A5C_0();
extern "C" void f_802D0A5C() {}
