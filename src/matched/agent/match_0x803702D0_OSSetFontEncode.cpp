// 0x803702D0 OSSetFontEncode (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 5,-25400(13); cmplwi 5,65535; beq 0f; b 6f; 0:; lis 4,-32768; lwz 0,0xcc(4); cmpwi 0,0; beq 1f; blt 4f; b 4f; 1:; lis 4,-13312; lhz 0,0x206e(4); rlwinm. 0,0,0,30,30; beq 2f; li 0,1; b 3f; 2:; li 0,0; 3:; sth 0,-25400(13); b 5f; 4:; li 0,0; sth 0,-25400(13); 5:; lis 4,-32713; lhz 5,-25400(13); addi 0,4,2136; stw 0,-22372(13); 6:; rlwinm 0,3,0,16,31; cmplwi 0,5; bgt 7f; cmplwi 0,3; sth 3,-25400(13); blt 7f; cmplwi 0,5; bgt 7f; lis 3,-32713; addi 0,3,2452; stw 0,-22372(13); 7:; mr 3,5"
extern "C" void f_803702D0() {}
