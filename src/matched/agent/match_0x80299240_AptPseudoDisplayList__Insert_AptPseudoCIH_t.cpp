// 0x80299240 AptPseudoDisplayList::Insert(AptPseudoCIH_t (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8(4); stw 4,0xc(5); stw 9,0x8(5); cmpwi 9,0; beq 0f; stw 5,0xc(9); 0:; lwz 9,0xc(5); stw 5,0x8(9)"
extern "C" void f_80299240() {}
