// 0x802C4830 StringPool::ClearTemporaryPool(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,-26892(13); cmpwi 0,0; beq 2f; 0:; lwz 3,-26892(13); lwz 9,0x8(3); lwz 31,0x10(3); lha 0,0x60(9); lwz 9,0x64(9); add 3,3,0; mtspr 8,9; blrl; lwz 11,-26892(13); cmpwi 11,0; beq 1f; lwz 9,0x8(11); li 4,3; lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; 1:; cmpwi 31,0; stw 31,-26892(13); bne 0b; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_802C4830() {}
