// 0x801D2074 PCTTarget::cCellInfo::Init(int, (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 5,5; bne 0f; li 3,0; blr; 0:; li 0,2; stw 4,0x4(3); stw 0,0x0(3); stw 5,0x14(3); lwz 0,0x0(5); cmpwi 0,0; stw 0,0x8(3); bne 1f; lis 0,-10852; ori 0,0,31669; stw 0,0x8(3); 1:; li 3,1"
extern "C" void f_801D2074() {}
