// 0x802B5B6C AptGlobal::objectMemberLookup(AptValue (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 3,-27000(13); mr 31,5; mr 4,31; addi 3,3,12; bl _s802B5B6C_0; mr. 3,3; beq 0f; lwz 0,0x0(3); andis. 9,0,2048; bne 1f; 0:; lwz 3,-26996(13); mr 4,31; addi 3,3,12; bl _s802B5B6C_1; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802B5B6C_0();
extern "C" void _s802B5B6C_1();
extern "C" void f_802B5B6C() {}
