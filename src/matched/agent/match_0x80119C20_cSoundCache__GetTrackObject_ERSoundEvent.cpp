// 0x80119C20 cSoundCache::GetTrackObject(ERSoundEvent (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); li 0,64; mr 31,3; mtspr 9,0; mr 29,4; li 10,0; 0:; lwzx 9,10,31; cmpwi 9,0; beq 2f; lwz 0,0x0(9); cmpw 0,29; bne 2f; lwz 11,0x100(31); addi 9,11,1; mr 0,9; cmpwi 9,0; bge 1f; addi 0,11,64; 1:; rlwinm 0,0,0,0,25; subf 0,0,9; stw 0,0x100(31); lwzx 3,10,31; b 9f; 2:; addi 10,10,4; bdnz 0b; cmpwi 5,0; beq 8f; li 10,0; 3:; lwz 11,0x100(31); rlwinm 30,11,2,0,29; lwzx 0,31,30; cmpwi 0,0; bne 5f; li 3,152; bl _s80119C20_0; mr 4,29; bl _s80119C20_1; stwx 3,31,30; cmpwi 3,0; beq 7f; lwz 9,0x100(31); rlwinm 0,9,2,0,29; addi 11,9,1; lwzx 3,31,0; cmpwi 11,0; mr 0,11; bge 4f; addi 0,9,64; 4:; rlwinm 0,0,0,0,25; subf 0,0,11; stw 0,0x100(31); b 9f; 5:; addi 9,11,1; mr 0,9; cmpwi 9,0; bge 6f; addi 0,11,64; 6:; rlwinm 0,0,0,0,25; addi 10,10,1; subf 0,0,9; cmpwi 10,63; stw 0,0x100(31); ble 3b; 7:; mr 3,31; bl _s80119C20_2; 8:; li 3,0; 9:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80119C20_0();
extern "C" void _s80119C20_1();
extern "C" void _s80119C20_2();
extern "C" void f_80119C20() {}
