// 0x80039C38 GetZodiacName(short) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,-32520(13); mr 31,3; cmpwi 0,0; bne 0f; bl _s80039C38_0; 0:; cmpwi 31,0; bgt 1f; li 31,1; b 2f; 1:; cmpwi 31,12; ble 2f; li 31,12; 2:; lis 9,-32697; rlwinm 0,31,2,0,29; addi 9,9,23376; li 11,0; lwzx 3,9,0; cmpwi 3,0; beq 3f; lwz 11,0x0(3); 3:; mr 3,11; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80039C38_0();
extern "C" void f_80039C38() {}
