// 0x8038D784 GXInitTexObjFilter (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 5,1; bne 0f; li 5,1; b 1f; 0:; li 5,0; 1:; lwz 0,0x0(3); rlwimi 0,5,4,27,27; addi 5,13,-25240; stw 0,0x0(3); lbzx 0,5,4; lwz 4,0x0(3); rlwimi 4,0,5,24,26; stw 4,0x0(3)"
extern "C" void f_8038D784() {}
