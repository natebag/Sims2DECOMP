// 0x8034D674 GetVoiceHandle(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,62; lis 9,-32690; mtspr 9,0; li 3,0; addi 11,9,-19244; 0:; lwz 0,0x24(11); cmpwi 0,0; bne 1f; lwz 0,0x40(11); rlwinm 0,0,0,1,31; stw 0,0x40(11); lbz 9,0x40(11); andi. 9,9,239; stb 9,0x40(11); lwz 0,0x40(11); rlwinm 0,0,0,2,0; stw 0,0x40(11); b 2f; 1:; addi 11,11,68; addi 3,3,1; bdnz 0b; 2:; cmpwi 3,62; bnelr; li 3,-1"
extern "C" void f_8034D674() {}
