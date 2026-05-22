// 0x80202EEC SKNTarget::FindActualSkinIndex(int) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 7,0; mr. 4,4; beq 3f; lwz 9,0x90(3); lis 11,-32688; addi 11,11,-13632; li 7,99; mulli 9,9,76; li 8,0; li 10,1; add 9,9,11; addi 3,9,4; 0:; lwz 0,0x0(3); addi 3,3,4; cmpwi 0,0; beq 1f; addi 8,8,1; 1:; cmpw 8,4; bne 2f; mr 7,10; 2:; addi 10,10,1; cmpwi 10,18; bgt 3f; cmpwi 7,99; beq 0b; 3:; mr 3,7"
extern "C" int f_80202EEC() {}
