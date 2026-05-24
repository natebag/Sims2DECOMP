// 0x802D785C ESemaphore::IsCreated(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(3); li 3,1; cmplwi 0,0; bnelr; li 3,0"

struct ESemaphore {
    void IsCreated();
};

void ESemaphore::IsCreated() {
}
