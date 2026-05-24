// 0x8004228C EGlobal::UseOptionsScreenAdjustXY(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; li 10,0; lwz 11,0x5f14(9); lbz 0,0x1f(11); extsb 8,0; cmpwi 8,-25; bge 0f; li 8,-25; b 1f; 0:; cmpwi 8,25; ble 2f; li 8,25; 1:; li 10,1; 2:; lis 9,-32697; lwz 11,0x5f14(9); lbz 0,0x20(11); extsb 0,0; cmpwi 0,-25; bge 3f; li 0,-25; b 4f; 3:; cmpwi 0,25; ble 5f; li 0,25; 4:; li 10,1; 5:; cmpwi 10,0; beq 6f; lis 9,-32697; addi 9,9,24012; lwz 11,0x148(9); stb 8,0x1f(11); lwz 10,0x148(9); stb 0,0x20(10); 6:; lwz 9,-26392(13); stw 0,0x24(9); stw 8,0x20(9)"

struct EGlobal {
    void UseOptionsScreenAdjustXY();
};

void EGlobal::UseOptionsScreenAdjustXY() {
}
