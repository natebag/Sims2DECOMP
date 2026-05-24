// 0x800F85D8 ObjectModuleImpl::OffsetObjectMap(CTilePt (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8240(1); mfspr 0,8; stmw 23,0x200c(1); stw 0,0x2034(1); mr 26,4; addi 24,3,52; li 27,0; addi 28,1,8; li 23,0; 0:; li 29,0; addi 25,27,1; rlwinm 30,27,7,0,24; 1:; mr 3,26; bl _s800F85D8_0; subf 31,3,29; mr 3,26; bl _s800F85D8_1; subf 9,3,27; li 0,0; cmpwi 31,0; blt 2f; cmpwi 9,0; blt 2f; cmpwi 31,63; bgt 2f; cmpwi 9,63; ble 3f; 2:; li 0,1; 3:; cmpwi 0,0; beq 4f; sthx 23,30,28; b 5f; 4:; add 0,31,31; rlwinm 9,9,7,0,24; add 0,0,9; lhzx 11,24,0; sthx 11,28,30; 5:; addi 29,29,1; addi 30,30,2; cmpwi 29,63; ble 1b; mr 27,25; cmpwi 27,63; ble 0b; mr 3,24; mr 9,28; li 11,8184; 6:; lwz 0,0x0(9); addic. 11,11,-24; stw 0,0x0(3); lwz 0,0x4(9); stw 0,0x4(3); lwz 0,0x8(9); stw 0,0x8(3); lwz 0,0xc(9); stw 0,0xc(3); lwz 0,0x10(9); stw 0,0x10(3); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(3); addi 3,3,24; bne 6b; lwz 0,0x0(9); stw 0,0x0(3); lwz 0,0x4(9); stw 0,0x4(3); lwz 0,0x2034(1); mtspr 8,0; lmw 23,0x200c(1); addi 1,1,8240"

extern "C" void _s800F85D8_0();
extern "C" void _s800F85D8_1();

struct ObjectModuleImpl {
    void OffsetObjectMap_CTilePt();
};

void ObjectModuleImpl::OffsetObjectMap_CTilePt() {
}
