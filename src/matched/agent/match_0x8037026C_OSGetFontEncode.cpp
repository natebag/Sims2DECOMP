// 0x8037026C OSGetFontEncode (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,-25400(13); cmplwi 3,65535; bnelr; lis 3,-32768; lwz 0,0xcc(3); cmpwi 0,0; beq 0f; blt 3f; b 3f; 0:; lis 3,-13312; lhz 0,0x206e(3); rlwinm. 0,0,0,30,30; beq 1f; li 0,1; b 2f; 1:; li 0,0; 2:; sth 0,-25400(13); b 4f; 3:; li 0,0; sth 0,-25400(13); 4:; lis 4,-32713; lhz 3,-25400(13); addi 0,4,2136; stw 0,-22372(13)"
extern "C" void f_8037026C() {}
