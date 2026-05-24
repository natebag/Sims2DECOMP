// 0x80189A78 HUDTarget::HUDHideComplete(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 3,0xe8(3); subfic 0,3,0; adde 3,0,3"

struct HUDTarget {
    void HUDHideComplete();
};

void HUDTarget::HUDHideComplete() {
}
