// 0x800BAE6C TArray<ENLatticePoints, (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="bne 0f; lwz 11,-26564(13); lwz 9,0x0(11); lwz 0,0x5c(9); lha 3,0x58(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,-24468(13); li 0,0; stw 0,0x418(9); 0:; li 3,1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; li 3,1; blr; li 3,1; blr; lwz 3,0x14(3)"
extern "C" void f_800BAE6C() {}
