// 0x8000DFA8 AptLine::UnlinkWord(AptWord (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 11,3; li 9,0; lwz 3,0x4(11); 0:; cmpwi 3,0; beqlr; cmpw 3,4; beq 1f; mr 9,3; lwz 3,0x0(3); b 0b; 1:; cmpwi 3,0; beqlr; cmpwi 9,0; beq 2f; lwz 0,0x0(3); stw 0,0x0(9); blr; 2:; lwz 0,0x0(3); stw 0,0x4(11)"
extern "C" void f_8000DFA8() {}
