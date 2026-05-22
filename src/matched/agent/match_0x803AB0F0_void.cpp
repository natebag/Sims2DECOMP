// 0x803AB0F0 void (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stw 0,0x34(1); lwz 9,0x4(3); lwz 0,0x0(9); stw 9,0x10(1); stw 0,0x8(1); lwz 9,0x4(4); lwz 0,0x0(9); stw 9,0x20(1); stw 0,0x18(1); b 2f; 0:; addi 3,4,8; addi 4,11,8; bl _s803AB0F0_0; cmpwi 3,0; beq 1f; lwz 9,0x18(1); lwz 3,0x8(1); stw 9,0x28(1); mr 4,9; lwz 0,0x0(9); mr 5,0; stw 0,0x28(1); bl _s803AB0F0_1; lwz 0,0x28(1); stw 0,0x18(1); b 2f; 1:; lwz 9,0x8(1); lwz 0,0x0(9); stw 0,0x8(1); 2:; lwz 0,0x10(1); li 9,1; lwz 11,0x8(1); mr 3,0; cmpw 11,0; bne 3f; li 9,0; 3:; cmpwi 9,0; lwz 4,0x18(1); lwz 5,0x20(1); beq 5f; li 0,1; cmpw 4,5; bne 4f; li 0,0; 4:; cmpwi 0,0; bne 0b; 5:; li 0,1; cmpw 4,5; bne 6f; li 0,0; 6:; cmpwi 0,0; beq 7f; bl _s803AB0F0_2; 7:; lwz 0,0x34(1); mtspr 8,0; addi 1,1,48"
extern "C" void _s803AB0F0_0();
extern "C" void _s803AB0F0_1();
extern "C" void _s803AB0F0_2();
extern "C" void f_803AB0F0() {}
