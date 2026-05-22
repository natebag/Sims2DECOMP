// 0x80037234 RemapWallShadowId(unsigned (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32702; li 7,0; addi 9,9,15020; li 8,0; addi 6,9,40; 0:; li 0,9; add 11,8,6; mtspr 9,0; li 10,0; 1:; lwz 0,0x0(11); addi 11,11,4; cmpw 0,3; bne 3f; 2:; lwzx 3,10,9; blr; 3:; addi 10,10,4; bdnz 1b; addi 7,7,1; addi 8,8,40; cmpwi 7,3; ble 0b; lis 9,-32702; li 7,0; addi 9,9,15020; li 8,0; addi 6,9,200; 4:; li 0,9; add 11,8,6; mtspr 9,0; li 10,0; 5:; lwz 0,0x0(11); addi 11,11,4; cmpw 0,3; beq 2b; addi 10,10,4; bdnz 5b; addi 7,7,1; addi 8,8,40; cmpwi 7,9; ble 4b"
extern "C" int f_80037234() {}
