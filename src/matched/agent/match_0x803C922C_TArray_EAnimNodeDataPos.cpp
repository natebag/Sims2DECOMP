// 0x803C922C TArray<EAnimNodeDataPos, (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 11,4,-1; cmpwi 4,0; beqlr; lis 9,-32697; li 0,0; addi 9,9,-8960; 0:; addi 3,3,36; cmpwi 11,0; stw 9,-36(3); addi 11,11,-1; stw 0,-4(3); bne 0b"
extern "C" void f_803C922C() {}
