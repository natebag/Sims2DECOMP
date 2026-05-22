// 0x803371C0 THPPlayerGetVolume(void) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32691; addi 9,9,14656; lwz 0,0xa0(9); cmpwi 0,0; bne 0f; li 3,-1; b 1f; 0:; lfs f0,0xdc(9); fctiwz f13,f0; stfd f13,0x8(1); lwz 3,0xc(1); 1:; addi 1,1,16"
extern "C" void f_803371C0() {}
