// 0x803658F0 PoolAlloc (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 10,3; bne 1f; 0:; li 3,0; blr; 1:; lwz 11,0xc(10); cmpwi 11,0; beq 0b; lwz 0,0x0(11); li 9,0; stw 0,0xc(10); stw 9,0x4(11); lwz 0,0x10(10); stw 0,0x0(11); lwz 9,0x10(10); cmpwi 9,0; beq 2f; stw 11,0x4(9); 2:; lwz 9,0x8(10); addi 3,11,16; stw 11,0x10(10); addi 9,9,1; stw 9,0x8(10)"
extern "C" void f_803658F0() {}
