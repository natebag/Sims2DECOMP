// 0x8025544C IsLeapYear (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="srawi 0,3,2; addze 0,0; rlwinm 0,0,2,0,29; subfc 0,0,3; cmpwi 0,0; li 5,1; li 6,0; bne 0f; lis 4,20972; addi 0,4,-31457; mulhw 0,0,3; srawi 0,0,5; rlwinm 4,0,1,31,31; add 0,0,4; mulli 0,0,100; subf 0,0,3; cmpwi 0,0; beq 0f; mr 6,5; 0:; cmpwi 6,0; bne 1f; lis 4,20972; addi 0,4,-31457; mulhw 0,0,3; srawi 0,0,7; rlwinm 4,0,1,31,31; add 0,0,4; mulli 0,0,400; subf 0,0,3; cmpwi 0,0; beq 1f; li 5,0; 1:; mr 3,5"
extern "C" int f_8025544C() {}
