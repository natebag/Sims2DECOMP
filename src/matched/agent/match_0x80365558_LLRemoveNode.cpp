// 0x80365558 LLRemoveNode (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x88(3); cmpw 4,0; bne 0f; lwz 0,0x0(4); stw 0,0x88(3); cmpwi 0,0; bne 2f; b 1f; 0:; lwz 0,0x8c(3); cmpw 4,0; bne 2f; lwz 0,0x4(4); 1:; stw 0,0x8c(3); 2:; lwz 9,0x4(4); cmpwi 9,0; beq 3f; lwz 0,0x0(4); stw 0,0x0(9); 3:; lwz 9,0x0(4); cmpwi 9,0; beq 4f; lwz 0,0x4(4); stw 0,0x4(9); 4:; lwz 9,0x84(3); addi 9,9,-1; cmpwi 9,0; stw 9,0x84(3); bge 5f; li 0,0; stw 0,0x84(3); 5:; li 0,0; stw 0,0x4(4); stw 0,0x0(4)"
extern "C" void f_80365558() {}
