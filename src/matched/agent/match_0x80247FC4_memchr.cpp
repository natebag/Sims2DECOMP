// 0x80247FC4 memchr (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,0,24,31; cmplwi 5,3; ble 5f; andi. 0,3,3; bne 5f; li 0,4; mr 10,3; mtspr 9,0; li 7,0; 0:; rlwinm 0,7,8,0,23; add 7,0,4; bdnz 0b; cmplwi 5,3; ble 4f; lis 8,-32640; ori 8,8,32896; 1:; lwz 11,0x0(10); xor 11,11,7; addis 9,11,-257; addi 9,9,-257; andc 11,9,11; and. 0,11,8; beq 3f; li 0,4; mr 3,10; mtspr 9,0; 2:; lbz 0,0x0(3); cmpw 0,4; beqlr; addi 3,3,1; bdnz 2b; 3:; addi 5,5,-4; addi 10,10,4; cmplwi 5,3; bgt 1b; 4:; mr 3,10; 5:; cmpwi 5,0; addi 5,5,-1; beq 7f; 6:; lbz 0,0x0(3); cmpw 0,4; beqlr; cmpwi 5,0; addi 3,3,1; addi 5,5,-1; bne 6b; 7:; li 3,0"
extern "C" int f_80247FC4() {}
