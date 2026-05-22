// 0x802EF7B8 EAnimController::SetTrackPos(EACTrack (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mr. 4,4; beq 0f; lwz 0,0xa8(4); cmpwi 0,1; bne 0f; lwz 8,0x7c(4); lis 0,17200; lis 10,-32702; lwz 9,0x18(8); cmpwi 5,0; lfd f13,-4328(10); addi 9,9,-1; xoris 9,9,32768; stw 9,0xc(1); stw 0,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f1,f0; stfs f0,0x40(4); beq 0f; lwz 0,-26812(13); stw 0,0x38(4); 0:; addi 1,1,16"
extern "C" void f_802EF7B8() {}
