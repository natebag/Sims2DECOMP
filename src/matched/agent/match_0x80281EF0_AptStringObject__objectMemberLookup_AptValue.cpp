// 0x80281EF0 AptStringObject::objectMemberLookup(AptValue (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 3,0x24(30); mr 31,5; lwz 9,0x8(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; bne 0f; mr 3,30; mr 4,29; mr 5,31; bl _s80281EF0_0; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80281EF0_0();
extern "C" void f_80281EF0() {}
