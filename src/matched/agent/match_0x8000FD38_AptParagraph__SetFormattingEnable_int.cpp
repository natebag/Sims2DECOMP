// 0x8000FD38 AptParagraph::SetFormattingEnable(int) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); cmpwi 3,0; beqlr; 0:; lwz 11,0x4(3); cmpwi 11,0; beq 6f; mcrf cr6,cr0; cmpwi 7,4,0; 1:; lwz 9,0xc(11); cmpwi 9,0; beq 3f; li 0,1; bne cr7,2f; li 0,0; 2:; stw 0,0x20(9); 3:; lwz 9,0x10(11); cmpwi 9,0; beq 5f; li 0,1; bne cr7,4f; li 0,0; 4:; stw 0,0x20(9); 5:; bne cr6,1b; 6:; lwz 3,0x0(3); cmpwi 3,0; bne 0b"
extern "C" void f_8000FD38() {}
