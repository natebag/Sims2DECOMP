// 0x8038D290 __GetImageTileCount (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 3,60; bgt 0f; lis 9,-32698; addi 9,9,-23304; rlwinm 0,3,2,0,29; lwzx 0,9,0; mtspr 9,0; bctr; li 11,3; li 12,3; b 1f; li 11,3; li 12,2; b 1f; li 11,2; li 12,2; b 1f; 0:; li 12,0; li 11,0; 1:; rlwinm. 0,4,0,16,31; bne 2f; li 4,1; 2:; rlwinm. 0,5,0,16,31; bne 3f; li 5,1; 3:; li 10,1; slw 9,10,11; rlwinm 4,4,0,16,31; addi 0,9,-1; add 0,4,0; sraw 0,0,11; slw 4,10,12; stw 0,0x0(6); rlwinm 5,5,0,16,31; addi 0,4,-1; add 0,5,0; sraw 0,0,12; cmpwi 3,6; stw 0,0x0(7); beq 4f; cmpwi 3,22; beq 4f; li 10,0; 4:; cmpwi 10,0; beq 5f; li 0,2; b 6f; 5:; li 0,1; 6:; stw 0,0x0(8)"
extern "C" void f_8038D290() {}
