// 0x800F2158 ObjectFolderImpl::ClearAllCaches(void) (580 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 27,0x4c(1); stw 0,0x64(1); mr 31,3; addi 28,1,56; lwz 9,0x0(31); lwz 0,0xd4(9); lha 3,0xd0(9); mtspr 8,0; add 3,31,3; blrl; li 0,0; addi 9,1,8; stw 0,0x4(9); addi 11,1,40; stw 0,0x8(9); mr 30,9; stw 0,0x4(11); addi 9,31,64; stw 0,0x8(11); addi 10,1,24; stw 9,0x28(1); stw 0,0x4(11); lwz 9,0x2c(1); cmpwi 9,255; bgt 2f; lwz 11,0x28(1); rlwinm 9,9,2,0,29; lwzx 9,11,9; b 1f; 0:; lwz 9,0x2c(1); addi 9,9,1; rlwinm 0,9,2,0,29; stw 9,0x2c(1); cmpwi 9,255; bgt 2f; lwz 9,0x28(1); lwzx 9,9,0; 1:; cmpwi 9,0; beq 0b; stw 9,0x30(1); 2:; lwz 11,0x28(1); lwz 0,0x2c(1); lwz 9,0x30(1); stw 0,0x1c(1); stw 9,0x20(1); stw 11,0x18(1); lwz 9,0x8(10); lwz 0,0x4(10); stw 11,0x8(1); stw 0,0x4(30); stw 9,0x8(30); addi 27,31,64; b 12f; 3:; lwz 31,0x8(30); li 29,0; mr 3,31; bl _s800F2158_0; lwz 11,0x3c(31); cmpw 29,11; beq 5f; cmpwi 11,0; beq 4f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 4:; stw 29,0x3c(31); 5:; lwz 11,0x64(31); li 29,0; cmpw 29,11; beq 7f; cmpwi 11,0; beq 6f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 6:; stw 29,0x64(31); 7:; lwz 9,0x8(30); cmpwi 9,0; beq 9f; lwz 0,0xa4(9); cmpwi 0,0; stw 0,0x8(30); bne 8f; lwz 9,0x4(30); addi 9,9,1; stw 9,0x4(30); 8:; lwz 0,0x8(30); cmpwi 0,0; bne 12f; 9:; lwz 9,0x4(30); cmpwi 9,255; bgt 12f; lwz 11,0x0(30); rlwinm 9,9,2,0,29; lwzx 9,11,9; b 11f; 10:; lwz 9,0x4(30); addi 9,9,1; rlwinm 0,9,2,0,29; stw 9,0x4(30); cmpwi 9,255; bgt 12f; lwz 9,0x0(30); lwzx 9,9,0; 11:; cmpwi 9,0; beq 10b; stw 9,0x8(30); 12:; li 0,0; li 9,256; stw 0,0x4(28); li 8,0; stw 0,0x8(28); stw 27,0x38(1); stw 9,0x4(28); lwz 0,0x4(30); lwz 9,0x3c(1); lwz 10,0x38(1); lwz 11,0x40(1); cmpw 0,9; stw 10,0x18(1); stw 9,0x1c(1); stw 11,0x20(1); bne 13f; lwz 0,0x8(30); cmpw 0,11; bne 13f; lwz 0,0x8(1); xor 8,0,10; subfic 9,8,0; adde 8,9,8; 13:; cmpwi 8,0; beq 3b; lwz 0,0x64(1); mtspr 8,0; lmw 27,0x4c(1); addi 1,1,96"

extern "C" void _s800F2158_0();

struct ObjectFolderImpl {
    void ClearAllCaches();
};

void ObjectFolderImpl::ClearAllCaches() {
}
