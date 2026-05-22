// 0x80303204 PSystemIsEmpty (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 3,3; beqlr; lwz 9,0x0(3); lwz 0,0x88(9); stw 0,0x90(9); b 1f; 0:; lwz 0,0x0(9); stw 0,0x90(11); 1:; lwz 11,0x0(3); li 0,0; lwz 9,0x90(11); cmpwi 9,0; beq 2f; lwz 0,0x8(9); 2:; cmpwi 0,0; bne 0b"
extern "C" void f_80303204() {}
