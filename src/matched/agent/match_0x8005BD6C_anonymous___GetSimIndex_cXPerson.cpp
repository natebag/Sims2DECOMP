// 0x8005BD6C {anonymous}::GetSimIndex(cXPerson (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; mr 11,3; addi 9,9,24012; lwz 0,0xbc(9); cmpw 0,11; beq 0f; lwz 0,0xc0(9); li 3,1; cmpw 0,11; beqlr; li 3,-1; blr; 0:; li 3,0"
extern "C" int f_8005BD6C() {}
