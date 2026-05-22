// 0x8037AC24 AXSetVoiceSrcType (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,0; stw 30,0x10(1); addi 30,3,0; bl _s8037AC24_0; cmpwi 31,2; addi 4,30,312; beq 3f; bge 0f; cmpwi 31,0; beq 1f; bge 2f; b 6f; 0:; cmpwi 31,4; beq 5f; bge 6f; b 4f; 1:; li 0,2; sth 0,0x8(4); b 6f; 2:; li 0,1; sth 0,0x8(4); b 6f; 3:; li 0,0; sth 0,0x8(4); sth 0,0xa(4); b 6f; 4:; li 0,0; sth 0,0x8(4); li 0,1; sth 0,0xa(4); b 6f; 5:; li 0,0; sth 0,0x8(4); li 0,2; sth 0,0xa(4); 6:; lwz 0,0x1c(30); ori 0,0,1; stw 0,0x1c(30); bl _s8037AC24_1; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037AC24_0();
extern "C" void _s8037AC24_1();
extern "C" void f_8037AC24() {}
