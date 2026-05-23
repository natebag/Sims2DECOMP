// 0x80250EF0 Reset (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="b 1f; 0:; mfspr 8,1008; ori 8,8,8; mtspr 1008,8; isync; sync; ori 0,0,0; b 2f; 1:; b 4f; 2:; mftb 5,268; 3:; mftb 6,268; subf 7,5,6; cmplwi 7,4388; blt 3b; ori 0,0,0; b 5f; 4:; b 6f; 5:; lis 8,-13312; ori 8,8,12288; li 4,3; stw 4,0x24(8); stw 3,0x24(8); ori 0,0,0; b 7f; 6:; b 8f; 7:; ori 0,0,0; b 7b; 8:; b 0b"
extern "C" void f_80250EF0() {}
