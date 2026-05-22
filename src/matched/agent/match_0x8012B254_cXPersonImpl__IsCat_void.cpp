// 0x8012B254 cXPersonImpl::IsCat(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x150(9); lwz 9,0x154(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 11,0x4(31); lwz 9,0x4(11); lwz 0,0x164(9); lha 3,0x160(9); mtspr 8,0; add 3,11,3; blrl; lwz 3,0x4(3); xori 3,3,3; subfic 0,3,0; adde 3,0,3; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_8012B254() {}
