// 0x801419D4 cSimulatorImpl::GetGlobalRef(short, (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,4,0,16,31; mr 11,3; cmplwi 0,47; ble 1f; 0:; li 3,0; blr; 1:; cmpwi 4,32; beq 0b; ble 2f; cmpwi 4,47; bgt 3f; cmpwi 4,46; blt 3f; b 0b; 2:; cmpwi 4,3; beq 0b; 3:; add 9,4,4; li 3,1; addi 9,9,20; add 9,11,9; stw 9,0x0(5)"

struct cSimulatorImpl {
    void GetGlobalRef();
};

void cSimulatorImpl::GetGlobalRef() {
}
