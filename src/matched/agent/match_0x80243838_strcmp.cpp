// 0x80243838 strcmp (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="or 0,3,4; andi. 9,0,3; bne 2f; lwz 9,0x0(3); lwz 0,0x0(4); cmpw 9,0; bne 2f; lis 10,-32640; ori 10,10,32896; 0:; lwz 11,0x0(3); addis 9,11,-257; addi 9,9,-257; andc 11,9,11; and. 0,11,10; beq 1f; li 3,0; blr; 1:; lwzu 9,0x4(3); lwzu 0,0x4(4); cmpw 9,0; beq 0b; 2:; lbz 0,0x0(3); extsb 9,0; cmpwi 9,0; beq 4f; lbz 0,0x0(4); extsb 0,0; cmpw 9,0; bne 4f; 3:; lbzu 0,0x1(3); addi 4,4,1; extsb 10,0; cmpwi 10,0; beq 4f; lbz 0,0x0(4); extsb 0,0; cmpw 10,0; beq 3b; 4:; lbz 0,0x0(3); lbz 3,0x0(4); subf 3,3,0"
extern "C" int f_80243838() {}
