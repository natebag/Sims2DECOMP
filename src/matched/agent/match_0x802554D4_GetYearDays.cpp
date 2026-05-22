// 0x802554D4 GetYearDays (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="srawi 0,3,2; addze 0,0; rlwinm 0,0,2,0,29; subfc 0,0,3; cmpwi 0,0; li 6,1; li 7,0; bne 0f; lis 5,20972; addi 0,5,-31457; mulhw 0,0,3; srawi 0,0,5; rlwinm 5,0,1,31,31; add 0,0,5; mulli 0,0,100; subf 0,0,3; cmpwi 0,0; beq 0f; mr 7,6; 0:; cmpwi 7,0; bne 1f; lis 5,20972; addi 0,5,-31457; mulhw 0,0,3; srawi 0,0,7; rlwinm 5,0,1,31,31; add 0,0,5; mulli 0,0,400; subf 0,0,3; cmpwi 0,0; beq 1f; li 6,0; 1:; cmpwi 6,0; beq 2f; lis 3,-32700; addi 3,3,-16360; b 3f; 2:; lis 3,-32700; addi 3,3,-16408; 3:; rlwinm 0,4,2,0,29; lwzx 3,3,0"
extern "C" int f_802554D4() {}
