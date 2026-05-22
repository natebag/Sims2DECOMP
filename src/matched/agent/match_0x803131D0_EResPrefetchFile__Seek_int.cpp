// 0x803131D0 EResPrefetchFile::Seek(int, (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 5,0; bne 0f; lwz 0,0x40(3); mr 3,4; cmpw 4,0; beqlr; blr; 0:; lwz 10,0x30(3); lwz 9,0x34(3); lwz 0,0x38(3); add 11,10,4; add 9,9,0; cmplw 11,9; blt 2f; cmpw 9,10; bne 1f; lwz 0,0x40(3); b 3f; 1:; lwz 0,0x40(3); stw 9,0x30(3); b 3f; 2:; lwz 0,0x40(3); stw 11,0x30(3); 3:; add 0,0,4; stw 0,0x40(3); lwz 3,0x40(3)"
extern "C" void f_803131D0() {}
