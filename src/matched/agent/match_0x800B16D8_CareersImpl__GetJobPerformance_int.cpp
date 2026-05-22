// 0x800B16D8 CareersImpl::GetJobPerformance(int) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); xoris 4,4,32768; stw 4,0xc(1); lis 0,17200; lis 11,-32706; lis 10,-32706; stw 0,0x8(1); mr 8,3; lfd f13,-26576(11); lfd f0,0x8(1); lfs f12,-26568(10); fsub f0,f0,f13; frsp f13,f0; fcmpu 0,f13,f12; bge 0f; li 3,0; b 3f; 0:; lis 9,-32706; lfs f0,-26564(9); fcmpu 0,f13,f0; bge 1f; li 3,1; b 3f; 1:; lis 9,-32706; lfs f0,-26560(9); fcmpu 0,f13,f0; bge 2f; li 3,2; b 3f; 2:; lis 9,-32706; li 3,4; lfs f0,-26556(9); fcmpu 0,f13,f0; bge 3f; li 3,3; 3:; lwz 9,0x10(8); li 0,0; lwz 9,0x0(9); cmpwi 9,0; beq 4f; lwz 0,-4(9); 4:; cmpw 3,0; bge 5f; rlwinm 3,3,2,0,29; add 3,9,3; b 6f; 5:; addi 3,8,28; 6:; addi 1,1,16"
extern "C" void f_800B16D8() {}
