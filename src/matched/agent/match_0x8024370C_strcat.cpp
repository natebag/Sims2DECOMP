// 0x8024370C strcat (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; andi. 0,31,3; bne 1f; lwz 9,0x0(31); lis 0,-32640; ori 0,0,32896; addis 11,9,-257; addi 11,11,-257; andc 9,11,9; and. 11,9,0; bne 1f; lis 0,-32640; ori 0,0,32896; 0:; lwzu 11,0x4(3); addis 9,11,-257; addi 9,9,-257; andc 11,9,11; and. 9,11,0; beq 0b; 1:; lbz 0,0x0(3); cmpwi 0,0; beq 3f; 2:; lbzu 0,0x1(3); cmpwi 0,0; bne 2b; 3:; bl _s8024370C_0; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8024370C_0();
extern "C" void f_8024370C() {}
