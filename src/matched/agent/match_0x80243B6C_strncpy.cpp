// 0x80243B6C strncpy (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="or 0,4,3; mr 10,3; andi. 9,0,3; bne 1f; cmplwi 5,3; ble 1f; lwz 11,0x0(4); lis 0,-32640; ori 0,0,32896; addis 9,11,-257; addi 9,9,-257; andc 11,9,11; and. 9,11,0; bne 1f; lis 8,-32640; ori 8,8,32896; 0:; lwz 0,0x0(4); addi 5,5,-4; addi 4,4,4; cmplwi 5,3; stw 0,0x0(10); addi 10,10,4; ble 1f; lwz 11,0x0(4); addis 9,11,-257; addi 9,9,-257; andc 11,9,11; and. 0,11,8; beq 0b; 1:; cmpwi 5,0; beq 2f; lbz 9,0x0(4); addi 5,5,-1; addi 4,4,1; extsb 0,9; stb 9,0x0(10); cmpwi 0,0; addi 10,10,1; bne 1b; 2:; mr 0,5; cmpwi 0,0; addi 5,5,-1; beqlr; li 9,0; 3:; mr 0,5; stb 9,0x0(10); cmpwi 0,0; addi 10,10,1; addi 5,5,-1; bne 3b"
extern "C" void f_80243B6C() {}
