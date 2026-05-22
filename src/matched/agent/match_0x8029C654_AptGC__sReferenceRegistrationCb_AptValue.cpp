// 0x8029C654 AptGC::sReferenceRegistrationCb(AptValue (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x0(4); andis. 9,0,16384; bne 0f; oris 0,0,16384; lwz 9,0x8(4); stw 0,0x0(4); lha 3,0x70(9); lwz 0,0x74(9); add 3,4,3; mtspr 8,0; blrl; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8029C654() {}
