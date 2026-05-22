// 0x8024379C strchr (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; rlwinm 4,4,0,24,31; andi. 0,3,3; bne 3f; li 8,4; li 0,0; mtspr 9,8; 0:; rlwinm 0,0,8,0,23; or 0,0,4; bdnz 0b; mr 3,9; lis 10,-32640; lwz 11,0x0(3); ori 10,10,32896; b 2f; 1:; lwzu 11,0x4(3); 2:; addis 9,11,-257; addi 9,9,-257; andc 9,9,11; and. 8,9,10; bne 3f; xor 11,11,0; addis 9,11,-257; addi 9,9,-257; andc 11,9,11; and. 9,11,10; beq 1b; 3:; lbz 0,0x0(3); b 5f; 4:; lbzu 0,0x1(3); 5:; cmpwi 0,0; beq 6f; cmpw 0,4; bne 4b; 6:; lbz 0,0x0(3); cmpw 0,4; beqlr; li 3,0"
extern "C" int f_8024379C() {}
