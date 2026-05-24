// 0x800EEE9C ObjectFolderImpl::GetPersonGlobNamespaceID(void) (492 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stw 0,0x4c(1); li 0,0; addi 9,1,8; stw 0,0x4(9); addi 11,1,40; stw 0,0x8(9); addi 3,3,64; stw 0,0x4(11); li 8,256; stw 0,0x8(11); mr 6,11; stw 3,0x28(1); mr 7,9; stw 8,0x4(11); addi 9,1,56; lwz 10,0x28(1); lwz 11,0x2c(1); lwz 8,0x30(1); stw 10,0x18(1); stw 11,0x1c(1); stw 8,0x20(1); stw 0,0x4(9); stw 0,0x8(9); stw 3,0x38(1); stw 0,0x4(9); lwz 9,0x3c(1); cmpwi 9,255; bgt 2f; lwz 11,0x38(1); rlwinm 9,9,2,0,29; lwzx 9,11,9; cmpwi 9,0; beq 1f; stw 9,0x40(1); b 2f; 0:; lwz 3,0xc(11); bl _s800EEE9C_0; b 9f; 1:; lwz 9,0x3c(1); addi 0,9,1; stw 0,0x3c(1); cmpwi 0,255; bgt 2f; lwz 9,0x38(1); rlwinm 0,0,2,0,29; lwzx 0,9,0; cmpwi 0,0; beq 1b; stw 0,0x40(1); 2:; lwz 9,0x3c(1); mr 10,7; lwz 0,0x40(1); stw 9,0x2c(1); stw 0,0x30(1); lwz 9,0x38(1); lwz 11,0x8(6); lwz 0,0x4(6); stw 9,0x8(1); stw 0,0x4(7); stw 11,0x8(7); stw 9,0x28(1); b 7f; 3:; lwz 11,0x8(10); lwz 9,0x38(11); lha 0,0x12(9); cmpwi 0,2; beq 0b; cmpwi 11,0; beq 5f; lwz 0,0xa4(11); cmpwi 0,0; stw 0,0x8(7); bne 4f; lwz 9,0x4(7); addi 9,9,1; stw 9,0x4(7); 4:; lwz 0,0x8(7); cmpwi 0,0; bne 7f; 5:; lwz 9,0x4(7); cmpwi 9,255; bgt 7f; lwz 11,0x0(7); rlwinm 9,9,2,0,29; lwzx 9,11,9; cmpwi 9,0; beq 6f; stw 9,0x8(7); b 7f; 6:; lwz 9,0x4(7); addi 0,9,1; stw 0,0x4(7); cmpwi 0,255; bgt 7f; lwz 9,0x0(7); rlwinm 0,0,2,0,29; lwzx 0,9,0; cmpwi 0,0; beq 6b; stw 0,0x8(7); 7:; lwz 9,0x4(10); li 11,0; lwz 0,0x1c(1); cmpw 9,0; bne 8f; lwz 9,0x8(7); lwz 0,0x20(1); cmpw 9,0; bne 8f; lwz 9,0x8(1); lwz 0,0x18(1); xor 11,9,0; subfic 8,11,0; adde 11,8,11; 8:; cmpwi 11,0; beq 3b; li 3,-1; 9:; lwz 0,0x4c(1); mtspr 8,0; addi 1,1,72"

extern "C" void _s800EEE9C_0();

struct ObjectFolderImpl {
    void GetPersonGlobNamespaceID();
};

void ObjectFolderImpl::GetPersonGlobNamespaceID() {
}
