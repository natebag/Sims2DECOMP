// 0x800B1CC8 CatalogResourceImpl::Load(ObjSelector (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,0x54(4); mr 31,3; li 4,0; lwz 3,0x1c(9); cmpwi 3,0; beq 0f; lwz 4,-4(3); 0:; rlwinm 4,4,4,0,27; add 4,3,4; bl _s800B1CC8_0; mr. 11,3; bne 1f; li 3,-1; b 2f; 1:; lwz 0,0x4(11); li 3,0; stw 0,0x4(31); lwz 9,0x8(11); stw 9,0x8(31); lwz 0,0xc(11); stw 0,0xc(31); 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800B1CC8_0();
extern "C" void f_800B1CC8() {}
