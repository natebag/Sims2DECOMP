// 0x802E1B80 ENgcFile::Seek(int, (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x68(3); cmpwi 5,1; bne 0f; add 0,11,4; b 2f; 0:; cmpwi 5,0; bne 1f; stw 4,0x68(3); b 3f; 1:; lwz 0,0x60(3); subf 0,4,0; 2:; stw 0,0x68(3); 3:; lwz 0,0x68(3); lwz 9,0x70(3); subf 0,11,0; add 9,9,0; cmplwi 9,4095; stw 9,0x70(3); ble 4f; li 0,1; stw 0,0x74(3); 4:; lwz 3,0x68(3)"
extern "C" void f_802E1B80() {}
