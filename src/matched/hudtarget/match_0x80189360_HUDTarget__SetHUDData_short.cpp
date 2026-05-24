// 0x80189360 HUDTarget::SetHUDData(short, (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,5; bne 1f; lwz 0,0xa0(3); cmpwi 0,0; beq 1f; 0:; li 3,0; blr; 1:; rlwinm 0,4,0,16,31; cmplwi 0,5; bgt 0b; lwz 0,0x104(3); add 9,4,4; addi 6,3,176; rlwinm 7,4,2,0,29; mulli 0,0,12; addi 10,3,134; addi 8,3,136; add 9,9,0; sthx 5,6,9; lhzx 11,10,7; lhzx 9,8,7; extsh 0,11; subf 0,0,5; subf 9,11,9; mulli 0,0,100; extsh 9,9; divw 0,0,9; cmpwi 0,0; blt 2f; mr 5,0; cmpwi 5,100; ble 3f; li 5,100; b 3f; 2:; li 5,0; 3:; lwz 0,0x104(3); addi 9,3,164; li 3,1; mulli 0,0,6; add 0,4,0; stbx 5,9,0"

struct HUDTarget {
    void SetHUDData_short();
};

void HUDTarget::SetHUDData_short() {
}
