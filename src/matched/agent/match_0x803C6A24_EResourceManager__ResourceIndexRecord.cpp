// 0x803C6A24 EResourceManager::ResourceIndexRecord (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 30,3; mr 31,4; mr 28,5; mr 29,6; 0:; addi 31,31,-12; b 2f; 1:; addi 30,30,12; 2:; mr 3,30; mr 4,28; mtspr 8,29; blrl; cmpwi 3,0; bne 1b; b 4f; 3:; addi 31,31,-12; 4:; mr 3,28; mr 4,31; mtspr 8,29; blrl; cmpwi 3,0; bne 3b; cmplw 30,31; bge 5f; lwz 8,0x4(30); lwz 7,0x8(30); lwz 10,0x0(30); stw 8,0xc(1); stw 10,0x8(1); stw 7,0x10(1); lwz 0,0x0(31); lwz 9,0x4(31); lwz 11,0x8(31); stw 0,0x0(30); stw 9,0x4(30); stw 11,0x8(30); stw 10,0x0(31); addi 30,30,12; stw 8,0x4(31); stw 7,0x8(31); b 0b; 5:; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void f_803C6A24() {}
