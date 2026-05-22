// 0x8023AAD8 CDirtyXmlNode::nextSibling(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0xc(3); li 10,0; cmpwi 9,0; beq 2f; lwz 11,0x10(9); addi 0,11,-1; cmpw 10,0; bge 2f; mr 11,0; lwz 9,0x1c(9); mtspr 9,11; 0:; lwz 0,0x0(9); cmpw 0,3; bne 1f; lwz 10,0x4(9); 1:; addi 9,9,4; bdnz 0b; 2:; mr 3,10"
extern "C" int f_8023AAD8() {}
