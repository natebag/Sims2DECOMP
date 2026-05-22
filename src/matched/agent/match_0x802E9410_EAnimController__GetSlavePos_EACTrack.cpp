// 0x802E9410 EAnimController::GetSlavePos(EACTrack (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lwz 11,0x7c(4); lwz 8,0x7c(5); lis 0,17200; lwz 9,0x18(11); mr 6,7; lwz 10,0x18(8); lis 11,-32702; addi 9,9,-1; lfd f11,-4640(11); xoris 9,9,32768; addi 10,10,-1; stw 9,0xc(1); xoris 10,10,32768; lfs f12,0x40(5); lis 9,-32702; stw 0,0x8(1); lfs f10,0x78(4); lfd f13,0x8(1); stw 10,0xc(1); lfs f9,-4632(9); fsub f13,f13,f11; stw 0,0x8(1); frsp f13,f13; lfd f0,0x8(1); fsub f0,f0,f11; frsp f0,f0; fdivs f12,f12,f0; fadds f1,f12,f10; fcmpu 0,f1,f9; ble 1f; fmr f0,f9; 0:; fsubs f1,f1,f0; fcmpu 0,f1,f0; bgt 0b; 1:; fmuls f1,f1,f13; addi 1,1,16"
extern "C" void f_802E9410() {}
