// 0x802E0DF8 EMemoryWriteStream::WriteToStream(EStream (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,3; mr 28,4; mr 30,5; mr. 29,6; beq 3f; 0:; mr 9,30; cmpwi 30,0; bge 1f; addi 9,30,4095; 1:; srawi 9,9,12; lwz 11,0x20(27); rlwinm 9,9,2,0,29; rlwinm 0,30,0,20,31; lwzx 10,11,9; subfic 31,0,4096; cmpw 29,31; add 4,10,0; bge 2f; mr 31,29; 2:; lwz 9,0x18(28); mr 5,31; add 30,30,31; lha 3,0x38(9); lwz 0,0x3c(9); add 3,28,3; mtspr 8,0; blrl; subf. 29,31,29; bne 0b; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void f_802E0DF8() {}
