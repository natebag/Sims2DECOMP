// 0x80382178 IsCard (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm. 0,3,0,0,15; beq 1f; addis 0,3,-32768; cmplwi 0,4; bne 0f; lhz 0,-25336(13); cmplwi 0,65535; bne 1f; 0:; li 3,0; blr; 1:; rlwinm. 0,3,0,30,31; beq 2f; li 3,0; blr; 2:; rlwinm 5,3,0,24,29; cmpwi 5,32; beq 6f; bge 4f; cmpwi 5,8; beq 6f; bge 3f; cmpwi 5,4; beq 6f; b 5f; 3:; cmpwi 5,16; beq 6f; b 5f; 4:; cmpwi 5,128; beq 6f; bge 5f; cmpwi 5,64; beq 6f; 5:; li 3,0; blr; 6:; lis 4,-32698; rlwinm 3,3,23,27,29; addi 0,4,-27464; add 3,0,3; lwz 3,0x0(3); cmpwi 3,0; bne 7f; li 3,0; blr; 7:; rlwinm 0,5,17,3,14; divwu 0,0,3; cmplwi 0,8; bge 8f; li 3,0; blr; 8:; li 3,1"
extern "C" int f_80382178() {}
