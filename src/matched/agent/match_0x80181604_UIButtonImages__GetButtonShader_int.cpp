// 0x80181604 UIButtonImages::GetButtonShader(int) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 11,-31492(13); cmpwi 11,0; bne 0f; li 3,0; b 2f; 0:; rlwinm 31,3,2,0,29; addi 9,11,56; lwzx 0,9,31; cmpwi 0,0; bne 1f; lwzx 4,11,31; lis 3,-32692; addi 3,3,-17444; bl _s80181604_0; lwz 9,-31492(13); addi 9,9,56; stwx 3,9,31; 1:; lwz 9,-31492(13); addi 9,9,56; lwzx 3,9,31; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80181604_0();
extern "C" void f_80181604() {}
