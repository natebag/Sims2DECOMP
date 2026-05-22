// 0x80370718 OSLoadFont (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,4,0; lhz 5,-25400(13); cmplwi 5,65535; beq 0f; b 6f; 0:; lis 4,-32768; lwz 0,0xcc(4); cmpwi 0,0; beq 1f; blt 4f; b 4f; 1:; lis 4,-13312; lhz 0,0x206e(4); rlwinm. 0,0,0,30,30; beq 2f; li 0,1; b 3f; 2:; li 0,0; 3:; sth 0,-25400(13); b 5f; 4:; li 0,0; sth 0,-25400(13); 5:; lis 4,-32713; lhz 5,-25400(13); addi 0,4,2136; stw 0,-22372(13); 6:; rlwinm 0,5,0,16,31; cmpwi 0,2; beq 11f; bge 7f; cmpwi 0,0; beq 8f; bge 9f; b 11f; 7:; cmpwi 0,6; bge 11f; b 10f; 8:; stw 3,-22384(13); addi 3,30,0; li 4,0; lwz 5,-22384(13); bl _s80370718_0; mr 31,3; b 12f; 9:; stw 3,-22380(13); addi 3,30,0; li 4,1; lwz 5,-22380(13); bl _s80370718_1; mr 31,3; b 12f; 10:; stw 3,-22384(13); addi 3,30,0; li 4,0; lwz 5,-22384(13); bl _s80370718_2; mr. 31,3; beq 12f; lwz 0,-22384(13); addi 3,30,0; li 4,1; add 0,0,31; stw 0,-22380(13); lwz 5,-22380(13); bl _s80370718_3; add 31,31,3; b 12f; 11:; li 31,0; 12:; mr 3,31; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80370718_0();
extern "C" void _s80370718_1();
extern "C" void _s80370718_2();
extern "C" void _s80370718_3();
extern "C" void f_80370718() {}
