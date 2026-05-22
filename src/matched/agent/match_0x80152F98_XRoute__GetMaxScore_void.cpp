// 0x80152F98 XRoute::GetMaxScore(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x58(3); cmpwi 0,-1; bne 2f; lwz 11,0x0(3); li 0,0; lwz 9,0x4(3); stw 0,0x58(3); cmpw 11,9; beq 2f; mr 10,9; 0:; lwz 9,0x8(11); lwz 0,0x58(3); cmpw 9,0; ble 1f; stw 9,0x58(3); 1:; addi 11,11,16; cmpw 11,10; bne 0b; 2:; lwz 3,0x58(3)"
extern "C" void f_80152F98() {}
