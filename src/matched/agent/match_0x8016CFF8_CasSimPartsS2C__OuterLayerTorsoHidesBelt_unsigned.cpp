// 0x8016CFF8 CasSimPartsS2C::OuterLayerTorsoHidesBelt(unsigned (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x8(3); extsb 5,5; cmpwi 0,0; beq 2f; cmpwi 6,2; bne 1f; 0:; li 3,0; blr; 1:; cmplwi 4,21; bge 0b; add 0,4,4; lis 9,-32706; add 0,5,0; addi 9,9,5415; lbzx 11,9,0; li 3,1; cmpwi 11,0; bnelr; li 3,0; blr; 2:; cmplwi 4,23; bge 0b; add 0,4,4; lis 9,-32706; add 0,5,0; addi 9,9,5369; lbzx 11,9,0; li 3,1; cmpwi 11,0; bnelr; li 3,0"
extern "C" int f_8016CFF8() {}
