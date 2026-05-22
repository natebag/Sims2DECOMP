// 0x8032C7F8 ENgcAudio::UnbindVoice(EVoice (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); addi 0,3,92; lwz 9,0x5c(3); stw 0,0x8(1); mr 31,4; li 4,-1; lha 3,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; lwz 4,0x8(31); cmpwi 4,-1; beq 2f; lwz 3,-26556(13); bl _s8032C7F8_0; lwz 3,-22572(13); li 5,1; lwz 4,0x4(31); bl _s8032C7F8_1; lis 9,-32692; lwz 0,0x8(31); lwz 11,0x36e0(9); li 10,0; cmpw 11,0; bne 0f; li 0,-1; stw 0,0x36e0(9); b 1f; 0:; addi 10,10,1; cmplwi 10,63; bgt 1f; lis 9,-32692; rlwinm 8,10,2,0,29; addi 9,9,14048; lwz 11,0x8(31); lwzx 0,9,8; cmpw 0,11; bne 0b; li 0,-1; stwx 0,9,8; 1:; li 0,-1; stw 0,0x8(31); 2:; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s8032C7F8_0();
extern "C" void _s8032C7F8_1();
extern "C" void f_8032C7F8() {}
