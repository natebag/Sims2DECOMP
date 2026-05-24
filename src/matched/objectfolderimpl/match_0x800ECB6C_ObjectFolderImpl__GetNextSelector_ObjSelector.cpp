// 0x800ECB6C ObjectFolderImpl::GetNextSelector(ObjSelector (460 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 27,0x44(1); stw 0,0x5c(1); mr 30,3; mr. 3,4; beq 7f; addi 28,1,24; bl _s800ECB6C_0; stw 3,0x38(1); rlwinm 10,3,0,24,31; addi 11,30,64; rlwinm 9,10,2,0,29; lwzx 31,11,9; li 0,0; stw 0,0x8(28); addi 27,1,56; stw 0,0x4(28); stw 11,0x18(1); stw 10,0x1c(1); addi 29,1,8; b 1f; 0:; lwz 31,0xa4(31); 1:; cmpwi 31,0; beq 2f; lwz 30,0x0(27); mr 3,31; bl _s800ECB6C_1; cmpw 30,3; bne 0b; stw 31,0x20(1); b 3f; 2:; li 0,256; stw 0,0x4(28); 3:; lwz 9,0x1c(1); lwz 0,0x18(1); lwz 11,0x20(1); stw 0,0x8(1); stw 9,0xc(1); stw 11,0x10(1); lwz 9,0x8(29); cmpwi 9,0; beq 5f; lwz 0,0xa4(9); cmpwi 0,0; stw 0,0x8(29); bne 4f; lwz 9,0x4(29); addi 9,9,1; stw 9,0x4(29); 4:; lwz 0,0x8(29); cmpwi 0,0; bne 10f; 5:; lwz 9,0x4(29); cmpwi 9,255; bgt 10f; lwz 11,0x0(29); rlwinm 9,9,2,0,29; lwzx 9,11,9; cmpwi 9,0; beq 6f; stw 9,0x8(29); b 10f; 6:; lwz 9,0x4(29); addi 0,9,1; stw 0,0x4(29); cmpwi 0,255; bgt 10f; lwz 9,0x0(29); rlwinm 0,0,2,0,29; lwzx 0,9,0; cmpwi 0,0; beq 6b; stw 0,0x8(29); b 10f; 7:; addi 9,1,40; addi 0,30,64; stw 3,0x4(9); addi 29,1,8; stw 3,0x8(9); stw 0,0x28(1); stw 3,0x4(9); lwz 9,0x2c(1); cmpwi 9,255; bgt 9f; lwz 11,0x28(1); rlwinm 9,9,2,0,29; lwzx 9,11,9; cmpwi 9,0; beq 8f; stw 9,0x30(1); b 9f; 8:; lwz 9,0x2c(1); addi 0,9,1; stw 0,0x2c(1); cmpwi 0,255; bgt 9f; lwz 9,0x28(1); rlwinm 0,0,2,0,29; lwzx 0,9,0; cmpwi 0,0; beq 8b; stw 0,0x30(1); 9:; lwz 0,0x28(1); lwz 9,0x2c(1); lwz 11,0x30(1); stw 0,0x8(1); stw 9,0xc(1); stw 11,0x10(1); 10:; lwz 3,0x8(29); lwz 0,0x5c(1); mtspr 8,0; lmw 27,0x44(1); addi 1,1,88"

extern "C" void _s800ECB6C_0();
extern "C" void _s800ECB6C_1();

struct ObjectFolderImpl {
    void GetNextSelector_ObjSelector();
};

void ObjectFolderImpl::GetNextSelector_ObjSelector() {
}
