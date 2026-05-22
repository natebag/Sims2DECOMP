// 0x8016D820 CasSimPartsS2C::GetBodyPartName(eBodyPartS2C) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); lis 9,-32706; addi 10,1,8; mr 8,10; addi 9,9,4592; li 0,96; 0:; lwz 11,0x0(9); addic. 0,0,-24; stw 11,0x0(10); lwz 11,0x4(9); stw 11,0x4(10); lwz 11,0x8(9); stw 11,0x8(10); lwz 11,0xc(9); stw 11,0xc(10); lwz 11,0x10(9); stw 11,0x10(10); lwz 11,0x14(9); addi 9,9,24; stw 11,0x14(10); addi 10,10,24; bne 0b; lwz 11,0x0(9); rlwinm 0,4,0,24,31; cmplwi 0,25; stw 11,0x0(10); lwz 11,0x4(9); stw 11,0x4(10); bgt 1f; extsb 0,4; rlwinm 0,0,2,0,29; lwzx 3,8,0; b 2f; 1:; lis 3,-32706; addi 3,3,1792; 2:; addi 1,1,112"
extern "C" void f_8016D820() {}
