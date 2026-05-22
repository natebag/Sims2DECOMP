// 0x800D01F8 NeighborhoodImpl::PrepareAndTestLot(StringBuffer (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 23,0x1c(1); stw 0,0x44(1); mr 28,4; bl _s800D01F8_0; lis 9,-32706; addi 4,1,8; lwz 11,-22036(9); mr 23,4; addi 9,9,-22036; lwz 26,-21484(13); stw 11,0x8(1); lwz 10,0x8(9); lwz 0,0x4(9); lwz 11,0x0(4); lwz 27,-21508(13); stw 0,0x4(4); cmpwi 11,0; stw 10,0x8(4); beq 2f; lis 25,-32706; lis 24,-32706; li 29,0; li 30,0; 0:; lwz 9,0x0(26); lwzx 31,4,30; lha 3,0xe0(9); lwz 0,0xe4(9); mr 4,31; add 3,26,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; lwz 9,0x0(27); mr 4,31; lha 3,0x78(9); lwz 0,0x7c(9); add 3,27,3; mtspr 8,0; blrl; mr. 31,3; beq 1f; addi 4,25,-22024; mr 3,28; bl _s800D01F8_1; lwz 4,0x14(31); mr 3,28; li 5,-1; bl _s800D01F8_2; mr 3,28; addi 4,24,-21988; li 5,-1; bl _s800D01F8_3; b 2f; 1:; addi 29,29,4; mr 4,23; lwzx 0,4,29; addi 30,30,4; cmpwi 0,0; bne 0b; 2:; lwz 0,0x44(1); mtspr 8,0; lmw 23,0x1c(1); addi 1,1,64"
extern "C" void _s800D01F8_0();
extern "C" void _s800D01F8_1();
extern "C" void _s800D01F8_2();
extern "C" void _s800D01F8_3();
extern "C" void f_800D01F8() {}
