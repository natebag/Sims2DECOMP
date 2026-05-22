// 0x800E3200 TArray<ENLatticePoints, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 11,1; beq 0f; lwz 3,0x4(31); li 4,8; lwz 9,0x4(3); lha 0,0x1d0(9); lwz 9,0x1d4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; li 3,1; bne 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" int f_800E3200() {}
