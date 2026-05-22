// 0x8008BAAC ELiveMode::ELiveMode(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); lis 10,-32707; lis 11,-32698; lfs f0,0x7d3c(10); mr 9,3; li 0,0; li 10,1; addi 11,11,-10176; stw 10,0x34(9); stw 11,0x8(9); lis 8,-32697; stw 0,0xc(9); li 11,-1; stfs f0,0x10(9); stw 10,0x0(9); stw 0,0x44(9); stw 0,0x30(9); stw 9,0x5c48(8); stw 11,0x54(9); stw 0,0x8(1); stw 10,0x10(1); addi 1,1,24"
extern "C" void f_8008BAAC() {}
