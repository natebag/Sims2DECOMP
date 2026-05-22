// 0x802438E0 strcpy (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="or 0,4,3; mr 11,3; andi. 9,0,3; bne 2f; lwz 11,0x0(4); lis 0,-32640; ori 0,0,32896; mr 10,3; addis 9,11,-257; addi 9,9,-257; andc 11,9,11; and. 9,11,0; bne 1f; lis 8,-32640; ori 8,8,32896; 0:; lwz 0,0x0(4); stw 0,0x0(10); addi 10,10,4; lwzu 11,0x4(4); addis 9,11,-257; addi 9,9,-257; andc 11,9,11; and. 0,11,8; beq 0b; 1:; mr 11,10; 2:; lbz 0,0x0(4); addi 4,4,1; extsb 9,0; stb 0,0x0(11); cmpwi 9,0; addi 11,11,1; bne 2b"
extern "C" void f_802438E0() {}
