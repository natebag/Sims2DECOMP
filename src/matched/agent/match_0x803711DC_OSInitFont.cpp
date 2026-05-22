// 0x803711DC OSInitFont (524 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); lhz 5,-25400(13); cmplwi 5,65535; beq 0f; b 6f; 0:; lis 4,-32768; lwz 0,0xcc(4); cmpwi 0,0; beq 1f; blt 4f; b 4f; 1:; lis 4,-13312; lhz 0,0x206e(4); rlwinm. 0,0,0,30,30; beq 2f; li 0,1; b 3f; 2:; li 0,0; 3:; sth 0,-25400(13); b 5f; 4:; li 0,0; sth 0,-25400(13); 5:; lis 4,-32713; lhz 5,-25400(13); addi 0,4,2136; stw 0,-22372(13); 6:; rlwinm 0,5,0,16,31; cmpwi 0,2; beq 15f; bge 7f; cmpwi 0,0; beq 8f; bge 10f; b 15f; 7:; cmpwi 0,6; bge 15f; b 12f; 8:; stw 3,-22384(13); addis 3,3,2; addi 3,3,-12000; lwz 5,-22384(13); li 4,0; bl _s803711DC_0; cmplwi 3,0; bne 9f; li 3,0; b 16f; 9:; lwz 3,-22384(13); lwz 4,0x24(3); addi 0,4,31; rlwinm 0,0,0,0,26; stw 0,0x24(3); add 4,3,4; lwz 3,-22384(13); lwz 0,0x24(3); add 5,3,0; bl _s803711DC_1; b 15f; 10:; stw 3,-22380(13); addis 3,3,13; addi 3,3,16128; lwz 5,-22380(13); li 4,1; bl _s803711DC_2; cmplwi 3,0; bne 11f; li 3,0; b 16f; 11:; lwz 3,-22380(13); lwz 4,0x24(3); addi 0,4,31; rlwinm 0,0,0,0,26; stw 0,0x24(3); add 4,3,4; lwz 3,-22380(13); lwz 0,0x24(3); add 5,3,0; bl _s803711DC_3; b 15f; 12:; stw 3,-22384(13); addis 31,3,15; addi 31,31,16416; lwz 5,-22384(13); addi 3,31,0; li 4,0; bl _s803711DC_4; cmplwi 3,0; bne 13f; li 3,0; b 16f; 13:; lwz 3,-22384(13); lwz 4,0x24(3); addi 0,4,31; rlwinm 0,0,0,0,26; stw 0,0x24(3); add 4,3,4; lwz 3,-22384(13); lwz 0,0x24(3); add 5,3,0; bl _s803711DC_5; lwz 5,-22384(13); addi 3,31,0; li 4,1; addis 5,5,2; addi 0,5,288; stw 0,-22380(13); lwz 5,-22380(13); bl _s803711DC_6; cmplwi 3,0; bne 14f; li 3,0; b 16f; 14:; lwz 3,-22380(13); lwz 4,0x24(3); addi 0,4,31; rlwinm 0,0,0,0,26; stw 0,0x24(3); add 4,3,4; lwz 3,-22380(13); lwz 0,0x24(3); add 5,3,0; bl _s803711DC_7; 15:; li 3,1; 16:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s803711DC_0();
extern "C" void _s803711DC_1();
extern "C" void _s803711DC_2();
extern "C" void _s803711DC_3();
extern "C" void _s803711DC_4();
extern "C" void _s803711DC_5();
extern "C" void _s803711DC_6();
extern "C" void _s803711DC_7();
extern "C" void f_803711DC() {}
