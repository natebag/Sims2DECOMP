// 0x801F49A0 StaticCalcRefundAmount_Pack(int, (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mr. 3,3; beq 0f; cmpwi 4,0; beq 0f; cmpwi 5,0; bne 1f; 0:; li 3,0; b 3f; 1:; xoris 0,3,32768; stw 0,0xc(1); lis 7,17200; mr 10,11; xoris 0,4,32768; stw 7,0x8(1); lis 9,-32704; lfd f12,-23648(9); lis 8,-32704; lfd f13,0x8(1); mr 9,11; stw 0,0xc(1); fsub f13,f13,f12; lfs f10,-23640(8); stw 7,0x8(1); frsp f13,f13; lfd f0,0x8(1); fsub f0,f0,f12; frsp f0,f0; fdivs f13,f13,f0; fmuls f13,f13,f10; fmr f0,f13; fctiwz f11,f0; stfd f11,0x8(1); lwz 3,0xc(1); cmpwi 3,0; bgt 2f; li 3,1; 2:; mullw 3,3,5; 3:; addi 1,1,16"
extern "C" void f_801F49A0() {}
