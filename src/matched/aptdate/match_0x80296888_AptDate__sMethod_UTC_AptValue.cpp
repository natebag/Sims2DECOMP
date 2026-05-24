// 0x80296888 AptDate::sMethod_UTC(AptValue (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-22936(13)"

struct AptDate {
    void sMethod_UTC();
};

void AptDate::sMethod_UTC() {
}
