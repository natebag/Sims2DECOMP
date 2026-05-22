// 0x802D7374 FastAllocPool::Alloc(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 11,3; lwz 3,0x4(11); cmplwi 3,0; beqlr; lwz 9,0x4(3); lis 0,17477; ori 0,0,21333; stw 9,0x4(11); stw 0,0x0(3)"
extern "C" void f_802D7374() {}
