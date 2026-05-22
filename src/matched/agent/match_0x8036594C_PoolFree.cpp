// 0x8036594C PoolFree (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 11,3; addi 10,4,-16; lwz 0,0x8(11); cmpwi 0,0; bne 0f; li 3,-1; blr; 0:; lwz 0,0x10(11); cmpw 10,0; bne 1f; lwz 0,-16(4); stw 0,0x10(11); 1:; lwz 9,0x4(10); cmpwi 9,0; beq 2f; lwz 0,-16(4); stw 0,0x0(9); 2:; lwz 9,-16(4); cmpwi 9,0; beq 3f; lwz 0,0x4(10); stw 0,0x4(9); 3:; li 9,0; li 3,0; stw 9,0x4(10); lwz 0,0xc(11); stw 0,-16(4); stw 10,0xc(11); lwz 9,0x8(11); addi 9,9,-1; stw 9,0x8(11)"
extern "C" void f_8036594C() {}
