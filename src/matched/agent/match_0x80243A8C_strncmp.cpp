// 0x80243A8C strncmp (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 5,5; bne 1f; 0:; li 3,0; blr; 1:; or 0,3,4; andi. 9,0,3; bne 4f; mr 10,3; mr 8,4; cmplwi 5,3; ble 3f; lwz 9,0x0(3); lwz 0,0x0(4); cmpw 9,0; bne 3f; lis 7,-32640; ori 7,7,32896; 2:; addic. 5,5,-4; beq 0b; lwz 11,0x0(10); addis 9,11,-257; addi 9,9,-257; andc 11,9,11; and. 0,11,7; bne 0b; addi 10,10,4; addi 8,8,4; cmplwi 5,3; ble 3f; lwz 9,0x0(10); lwz 0,0x0(8); cmpw 9,0; beq 2b; 3:; mr 3,10; mr 4,8; 4:; mr 0,5; cmpwi 0,0; addi 5,5,-1; beq 6f; lbz 11,0x0(3); lbz 0,0x0(4); cmpw 11,0; bne 6f; 5:; cmpwi 5,0; beq 0b; cmpwi 11,0; beq 0b; lbzu 11,0x1(3); addi 5,5,-1; lbzu 0,0x1(4); cmpw 11,0; beq 5b; 6:; lbz 0,0x0(3); lbz 3,0x0(4); subf 3,3,0"
extern "C" int f_80243A8C() {}
