// 0x800B8CF0 cSoundCacheItem::Update(void) (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 30,0x10(31); cmpwi 30,0; bne 5f; lwz 0,0xc(31); cmpwi 0,0; beq 1f; lwz 3,-22572(13); lwz 4,0x0(31); bl _s800B8CF0_0; mr. 29,3; beq 5f; stw 30,0xc(31); mr 4,29; lwz 10,-22572(13); lwz 9,-21352(13); lwz 11,0xd1c(10); addi 9,9,-1; lha 3,0x40(11); lwz 0,0x44(11); add 3,10,3; stw 9,-21352(13); mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,29; bl _s800B8CF0_1; b 3f; 0:; li 0,1; stw 0,0x10(31); b 5f; 1:; lwz 9,0x14(31); cmpwi 9,0; beq 2f; addi 0,9,-1; b 4f; 2:; lwz 9,-21352(13); cmpwi 9,3; bgt 3f; addi 0,9,1; lwz 11,-22572(13); li 9,1; stw 0,-21352(13); stw 9,0xc(31); lwz 4,0x0(31); lwz 9,0xd1c(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; b 5f; 3:; li 0,15; 4:; stw 0,0x14(31); 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800B8CF0_0();
extern "C" void _s800B8CF0_1();
extern "C" void f_800B8CF0() {}
