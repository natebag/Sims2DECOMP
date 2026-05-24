// 0x803224F4 REffectsAttachment::OldLoad(EFile (652 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 28,0x60(1); stw 0,0x74(1); mr 31,3; mr. 29,4; beq 15f; addi 3,1,8; bl _s803224F4_0; lis 5,17729; addi 3,1,8; mr 4,29; ori 5,5,21571; li 6,1; li 7,1; bl _s803224F4_1; cmpwi 3,0; bne 0f; addi 3,1,8; li 4,2; bl _s803224F4_2; b 15f; 0:; addi 3,1,8; bl _s803224F4_3; lwz 9,0x18(1); lwz 0,0x10(31); cmpwi 9,0; rlwimi 0,9,8,0,23; stw 0,0x10(31); beq 14f; li 0,0; addi 3,1,32; stw 0,0x20(1); addi 9,1,40; stw 0,0x4(3); addi 6,1,56; stw 0,0x4(9); lwz 4,0x24(1); lwz 5,0x20(1); lwz 0,0x18(1); subf 9,5,4; rlwinm 0,0,27,5,31; srawi 9,9,5; cmplw 0,9; bge 3f; rlwinm 0,0,5,0,26; addi 30,31,20; add 0,0,5; addi 28,1,88; lwz 11,0x24(1); mr 9,0; cmpw 0,11; beq 2f; 1:; addi 9,9,32; cmpw 9,11; bne 1b; 2:; stw 0,0x24(1); b 4f; 3:; subf 5,9,0; bl _s803224F4_4; addi 30,31,20; addi 28,1,88; 4:; lwz 9,0x28(29); lwz 4,0x20(1); lwz 0,0x1c(9); lha 3,0x18(9); lwz 5,0x18(1); mtspr 8,0; add 3,29,3; blrl; li 9,0; lwz 5,0x14(31); li 10,0; lwz 0,0x24(1); stw 9,0x58(1); stw 10,0x5c(1); lwz 9,0x20(1); lwz 4,0x4(30); subf 0,9,0; subf 11,5,4; srawi 0,0,5; srawi 11,11,3; cmplw 0,11; bge 7f; rlwinm 0,0,3,0,28; add 0,0,5; lwz 11,0x4(30); mr 9,0; cmpw 0,11; beq 6f; 5:; addi 9,9,8; cmpw 9,11; bne 5b; 6:; stw 0,0x4(30); b 8f; 7:; subf 5,11,0; mr 3,30; mr 6,28; bl _s803224F4_5; 8:; lwz 9,0x20(1); li 7,0; lwz 0,0x24(1); subf 0,9,0; srawi. 9,0,5; ble 10f; li 6,0; li 8,0; li 10,0; 9:; lwz 9,0x20(1); addi 7,7,1; lwz 11,0x14(31); add 9,9,8; lbz 0,0xd(9); add 11,11,10; stb 0,0x1(11); lwz 9,0x20(1); lwz 11,0x14(31); add 9,9,8; lwz 0,0x1c(9); add 11,11,10; stw 0,0x4(11); lwz 9,0x20(1); lwz 11,0x14(31); add 9,9,8; lbz 0,0xc(9); addi 8,8,32; stbx 0,11,10; lwz 9,0x14(31); add 9,9,10; sth 6,0x2(9); addi 10,10,8; lwz 0,0x24(1); lwz 9,0x20(1); subf 0,9,0; srawi 0,0,5; cmpw 7,0; blt 9b; 10:; lwz 9,0x20(1); lwz 0,0x24(1); mr 3,9; cmpw 9,0; beq 12f; 11:; addi 9,9,32; cmpw 9,0; bne 11b; 12:; cmpwi 3,0; beq 14f; lwz 0,0x2c(1); subf 0,3,0; rlwinm 4,0,0,0,26; cmplwi 4,128; ble 13f; bl _s803224F4_6; b 14f; 13:; bl _s803224F4_7; 14:; addi 3,1,8; li 4,2; bl _s803224F4_8; 15:; lwz 0,0x74(1); mtspr 8,0; lmw 28,0x60(1); addi 1,1,112"

extern "C" void _s803224F4_0();
extern "C" void _s803224F4_1();
extern "C" void _s803224F4_2();
extern "C" void _s803224F4_3();
extern "C" void _s803224F4_4();
extern "C" void _s803224F4_5();
extern "C" void _s803224F4_6();
extern "C" void _s803224F4_7();
extern "C" void _s803224F4_8();

struct REffectsAttachment {
    void OldLoad_EFile();
};

void REffectsAttachment::OldLoad_EFile() {
}
