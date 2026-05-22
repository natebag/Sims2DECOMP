// 0x802B5E14 AptObject::objectMemberLookup(AptValue (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,0x0(5); lis 4,-32703; addi 4,4,21068; addi 3,3,8; bl _s802B5E14_0; cmpwi 3,0; li 3,0; bne 0f; lwz 3,-22908(13); 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802B5E14_0();
extern "C" void f_802B5E14() {}
