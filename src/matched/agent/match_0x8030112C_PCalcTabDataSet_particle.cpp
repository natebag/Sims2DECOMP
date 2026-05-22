// 0x8030112C PCalcTabDataSet(particle (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32702; lwz 0,0x168(4); lfs f0,-2080(9); li 8,0; lis 9,-32702; cmpw 8,0; fmuls f1,f1,f0; lfs f13,-2076(9); li 10,0; bge 3f; lis 9,-32702; lis 7,17200; lfd f12,-2072(9); addi 11,4,396; 0:; lfs f0,0x0(11); fadds f13,f13,f0; fcmpu 0,f1,f13; bge 1f; xoris 0,10,32768; stw 0,0xc(1); li 8,1; stw 7,0x8(1); lfd f0,0x8(1); fsub f0,f0,f12; frsp f0,f0; stfs f0,0x4c(3); b 2f; 1:; addi 11,11,132; addi 10,10,1; 2:; cmpwi 8,0; bne 4f; lwz 0,0x168(4); cmpw 10,0; blt 0b; 3:; cmpwi 8,0; bne 4f; lis 9,-32702; lfs f0,-2076(9); stfs f0,0x4c(3); 4:; addi 1,1,16"
extern "C" void f_8030112C() {}
