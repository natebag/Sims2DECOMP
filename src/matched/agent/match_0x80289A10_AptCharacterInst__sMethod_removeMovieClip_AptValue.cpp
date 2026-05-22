// 0x80289A10 AptCharacterInst::sMethod_removeMovieClip(AptValue (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); li 0,0; li 4,0; stw 0,0x8(1); mr 5,3; addi 6,1,8; bl _s80289A10_0; lwz 4,0x8(1); cmpwi 4,0; beq 1f; lwz 0,0x0(4); li 11,0; rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 0f; rlwinm 11,0,5,31,31; 0:; cmpwi 11,0; beq 1f; lwz 9,0x48(4); lwz 3,0x4c(9); addi 3,3,36; bl _s80289A10_1; 1:; lwz 3,-22936(13); lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s80289A10_0();
extern "C" void _s80289A10_1();
extern "C" void f_80289A10() {}
