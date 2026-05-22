// 0x80286C94 AptArray::objectMemberSet(AptValue (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,5; mr 29,4; lwz 3,0x0(31); mr 30,6; addi 3,3,8; bl _s80286C94_0; cmpwi 3,0; beq 1f; lwz 3,0x0(31); addi 3,3,8; bl _s80286C94_1; mr 4,3; mr. 5,30; bne 0f; lwz 5,-22936(13); 0:; mr 3,29; bl _s80286C94_2; li 3,1; b 2f; 1:; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80286C94_0();
extern "C" void _s80286C94_1();
extern "C" void _s80286C94_2();
extern "C" void f_80286C94() {}
