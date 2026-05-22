// 0x802CE3AC ERedBlackTree::Find(unsigned (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x8(3); lis 9,-32700; addi 9,9,-4812; cmpw 3,9; beq 4f; cmpwi 7,5,0; 0:; lwz 0,0x18(3); cmpw 4,0; bne 1f; beqlr cr7; lwz 0,0x1c(3); stw 0,0x0(5); blr; 1:; cmplw 4,0; bge 2f; lwz 3,0x0(3); b 3f; 2:; lwz 3,0x4(3); 3:; cmpw 3,9; bne 0b; 4:; li 3,0"
extern "C" void f_802CE3AC() {}
