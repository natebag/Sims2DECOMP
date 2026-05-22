// 0x801BBCF8 INGTarget::query_enabled(INGTarget::IngInfo (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 4,4; beq 0f; lwz 11,0x0(4); cmpwi 11,0; bne 1f; 0:; li 3,1; b 3f; 1:; lwz 4,0x4(4); cmpwi 4,0; beq 2f; lwz 10,0x454(3); cmplw 4,10; blt 2f; lha 0,0x2(11); lwz 9,0x444(3); mullw 0,0,10; cmpw 0,9; bgt 2f; lwz 9,0x28(11); lwz 0,-30260(13); cmpw 9,0; bgt 2f; lha 4,0x0(11); bl _s801BBCF8_0; subfic 0,3,0; adde 3,0,3; b 3f; 2:; li 3,0; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801BBCF8_0();
extern "C" void f_801BBCF8() {}
