// 0x802E1A8C ENgcFile::BufferReadRequest(unsigned (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,4; lwz 0,0x74(31); mr 29,5; li 30,0; cmpwi 0,0; beq 1f; lwz 0,0x68(31); li 10,4096; lwz 11,0x60(31); rlwinm 9,0,0,21,31; subf 6,9,0; stw 9,0x70(31); subf 11,6,11; cmplwi 11,4095; bgt 0f; addi 0,11,31; rlwinm 10,0,0,0,26; 0:; lwz 0,-26828(13); mr 5,10; lwz 4,0x6c(31); addi 3,31,44; add 0,0,10; li 7,2; stw 0,-26828(13); bl _s802E1A8C_0; stw 30,0x74(31); 1:; lwz 0,0x70(31); subfic 3,0,4096; cmpw 29,3; ble 2f; li 0,1; mr 30,3; stw 0,0x74(31); b 3f; 2:; mr 30,29; 3:; lwz 0,0x6c(31); mr 3,28; lwz 4,0x70(31); mr 5,30; add 4,0,4; crxor 6,6,6; bl _s802E1A8C_1; lwz 9,0x70(31); mr 3,30; lwz 0,0x68(31); add 9,9,30; add 0,0,30; stw 9,0x70(31); stw 0,0x68(31); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802E1A8C_0();
extern "C" void _s802E1A8C_1();
extern "C" void f_802E1A8C() {}
