// 0x800F0F34 ObjectFolderImpl::DeleteSelectorAnimLists(void) (488 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 26,0x48(1); stw 0,0x64(1); li 0,0; addi 9,1,8; stw 0,0x4(9); addi 11,1,40; stw 0,0x8(9); addi 10,3,64; stw 0,0x4(11); mr 29,9; stw 0,0x8(11); addi 8,1,24; stw 10,0x28(1); addi 27,1,56; stw 0,0x4(11); lwz 9,0x2c(1); cmpwi 9,255; bgt 2f; lwz 11,0x28(1); rlwinm 9,9,2,0,29; lwzx 9,11,9; b 1f; 0:; lwz 9,0x2c(1); addi 9,9,1; rlwinm 0,9,2,0,29; stw 9,0x2c(1); cmpwi 9,255; bgt 2f; lwz 9,0x28(1); lwzx 9,9,0; 1:; cmpwi 9,0; beq 0b; stw 9,0x30(1); 2:; lwz 11,0x28(1); lwz 0,0x2c(1); lwz 9,0x30(1); stw 0,0x1c(1); stw 9,0x20(1); stw 11,0x18(1); lwz 9,0x8(8); lwz 0,0x4(8); stw 11,0x8(1); stw 0,0x4(29); stw 9,0x8(29); addi 26,3,64; b 10f; 3:; lwz 9,0x8(29); li 28,0; li 30,4; addi 31,9,64; 4:; lwz 0,0x0(31); mr 3,0; cmpwi 0,0; beq 5f; bl _s800F0F34_0; stw 28,0x0(31); 5:; addi 31,31,4; addic. 30,30,-1; bne 4b; lwz 9,0x8(29); cmpwi 9,0; beq 7f; lwz 0,0xa4(9); cmpwi 0,0; stw 0,0x8(29); bne 6f; lwz 9,0x4(29); addi 9,9,1; stw 9,0x4(29); 6:; lwz 0,0x8(29); cmpwi 0,0; bne 10f; 7:; lwz 9,0x4(29); cmpwi 9,255; bgt 10f; lwz 11,0x0(29); rlwinm 9,9,2,0,29; lwzx 9,11,9; b 9f; 8:; lwz 9,0x4(29); addi 9,9,1; rlwinm 0,9,2,0,29; stw 9,0x4(29); cmpwi 9,255; bgt 10f; lwz 9,0x0(29); lwzx 9,9,0; 9:; cmpwi 9,0; beq 8b; stw 9,0x8(29); 10:; li 0,0; li 9,256; stw 0,0x4(27); li 8,0; stw 0,0x8(27); stw 26,0x38(1); stw 9,0x4(27); lwz 0,0x4(29); lwz 9,0x3c(1); lwz 10,0x38(1); lwz 11,0x40(1); cmpw 0,9; stw 10,0x18(1); stw 9,0x1c(1); stw 11,0x20(1); bne 11f; lwz 0,0x8(29); cmpw 0,11; bne 11f; lwz 0,0x8(1); xor 8,0,10; subfic 9,8,0; adde 8,9,8; 11:; cmpwi 8,0; beq 3b; lwz 0,0x64(1); mtspr 8,0; lmw 26,0x48(1); addi 1,1,96"

extern "C" void _s800F0F34_0();

struct ObjectFolderImpl {
    void DeleteSelectorAnimLists();
};

void ObjectFolderImpl::DeleteSelectorAnimLists() {
}
