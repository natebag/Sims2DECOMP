// 0x8023878C Emitter::SetCallbacks(void (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); stmw 30,0x8(1); lwz 11,0x7c(3); mr 12,9; lwz 30,0x18(1); lwz 31,0x1c(1); cmpwi 11,0; beq 8f; li 0,0; ori 0,0,65535; cmpw 4,0; beq 0f; stw 4,0x90(11); 0:; cmpw 6,0; beq 1f; lwz 9,0x7c(3); stw 6,0x98(9); 1:; cmpw 8,0; beq 2f; lwz 9,0x7c(3); stw 8,0xa0(9); 2:; cmpw 7,0; beq 3f; lwz 9,0x7c(3); stw 7,0x9c(9); 3:; cmpw 12,0; beq 4f; lwz 9,0x7c(3); stw 12,0xa4(9); 4:; cmpw 10,0; beq 5f; lwz 9,0x7c(3); stw 10,0xa8(9); 5:; cmpw 5,0; beq 6f; lwz 9,0x7c(3); stw 5,0x94(9); 6:; cmpw 31,0; beq 7f; lwz 9,0x7c(3); stw 31,0xb0(9); 7:; cmpw 30,0; beq 8f; lwz 9,0x7c(3); stw 30,0xac(9); 8:; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_8023878C() {}
