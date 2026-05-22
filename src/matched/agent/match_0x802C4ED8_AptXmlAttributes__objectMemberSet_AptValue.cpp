// 0x802C4ED8 AptXmlAttributes::objectMemberSet(AptValue (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x0(4); rlwinm 0,0,0,25,31; cmpwi 0,34; bne 3f; lwz 0,0x0(6); li 10,0; mr 9,0; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 0f; cmpwi 0,42; bne 1f; 0:; andis. 0,9,2048; beq 1f; li 10,1; 1:; cmpwi 10,0; beq 3f; lwz 10,0x24(4); rlwinm 0,9,0,25,31; cmpwi 0,1; lwz 11,0x0(5); lwz 9,0x0(10); addi 4,11,8; lha 0,0x28(9); addi 8,9,40; add 3,10,0; beq 2f; lwz 6,0x24(6); 2:; lwz 5,0xc(6); lwz 0,0x4(8); addi 5,5,8; mtspr 8,0; blrl; 3:; li 3,1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_802C4ED8() {}
