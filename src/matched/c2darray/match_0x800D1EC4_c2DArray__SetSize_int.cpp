// 0x800D1EC4 _c2DArray::SetSize(int, (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,5; lwz 0,0x4(31); mr 30,4; cmpw 29,0; bne 0f; lwz 0,0x8(31); cmpw 30,0; bne 0f; lwz 0,0xc(31); cmpwi 0,0; beq 1f; li 3,1; b 6f; 0:; lwz 3,0xc(31); cmpwi 3,0; beq 1f; lwz 9,-31944(13); mtspr 8,9; blrl; 1:; stw 29,0x4(31); cmpwi 30,0; stw 30,0x8(31); ble 2f; cmpwi 29,0; bgt 3f; 2:; li 0,0; li 3,1; stw 0,0xc(31); b 6f; 3:; mullw 3,30,29; lwz 0,0x14(31); lwz 10,-31948(13); rlwinm 9,30,2,0,29; mtspr 8,10; mullw 3,3,0; add 3,3,9; blrl; stw 3,0xc(31); cmpwi 3,0; beq 5f; lwz 0,0x8(31); li 7,1; rlwinm 0,0,2,0,29; add 0,3,0; stw 0,0x0(3); lwz 9,0x8(31); cmpw 7,9; bge 5f; li 8,4; 4:; lwz 0,0x14(31); addi 7,7,1; lwz 11,0x4(31); lwz 10,0xc(31); mullw 11,11,0; add 9,8,10; lwz 0,-4(9); add 0,0,11; stwx 0,8,10; addi 8,8,4; lwz 0,0x8(31); cmpw 7,0; blt 4b; 5:; lwz 0,0xc(31); li 3,1; cmpwi 0,0; bne 6f; li 3,0; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

struct c2DArray {
    void SetSize();
};

void c2DArray::SetSize() {
}
