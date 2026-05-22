// 0x8014ACB8 WantFear::Bookmark::IsDuplicateNode(WantFear::Bookmark (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 11,3; mr 31,4; lwz 10,0x4(11); lhz 9,0x0(11); lhz 0,0x0(31); cmpw 9,0; bne 0f; lwz 0,0x4(31); li 3,0; cmpw 10,0; bne 1f; mr 3,11; bl _s8014ACB8_0; mr 30,3; mr 3,31; bl _s8014ACB8_1; xor 3,30,3; subfic 0,3,0; adde 3,0,3; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8014ACB8_0();
extern "C" void _s8014ACB8_1();
extern "C" void f_8014ACB8() {}
