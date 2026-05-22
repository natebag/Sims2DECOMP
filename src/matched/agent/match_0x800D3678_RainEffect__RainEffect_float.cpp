// 0x800D3678 RainEffect::RainEffect(float, (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 5,21; lwz 4,-31932(13); lwz 9,0x0(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 26,1; bne 2f; b 1f; 0:; lwz 3,-32056(13); mr 5,21; lwz 4,-31932(13); li 6,1; bl _s800D3678_0; mr 26,3; b 2f; 1:; lwz 3,-26384(13); mr 5,21; lwz 8,0x0(18); li 6,8192; lwz 9,0x0(3); li 7,8192; lwz 4,-24284(13); lha 0,0x50(9); lwz 9,0x54(9); add 3,3,0; mtspr 8,9; blrl; mr 26,3; cmpwi 26,1; beq 0b; 2:; cmpwi 26,1; li 3,0; beq 3f; li 3,4; 3:; lwz 0,0x74(1); mtspr 8,0; lmw 15,0x2c(1); addi 1,1,112"
extern "C" void _s800D3678_0();
extern "C" int f_800D3678() {}
