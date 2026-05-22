// 0x802CB890 Rndf(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lwz 10,-26864(13); lis 0,16838; ori 0,0,20079; mullw 10,10,0; lis 7,17200; lis 9,-32702; lfd f0,-7368(9); lis 11,-32702; lfs f13,-7360(11); addi 10,10,12347; rlwinm 0,10,16,17,31; stw 10,-26864(13); stw 0,0xc(1); stw 7,0x8(1); lfd f1,0x8(1); fsub f1,f1,f0; frsp f1,f1; fmuls f1,f1,f13; addi 1,1,16"
extern "C" void f_802CB890() {}
