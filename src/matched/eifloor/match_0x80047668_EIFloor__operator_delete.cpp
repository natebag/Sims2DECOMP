// 0x80047668 EIFloor::operator delete(void*) (52B)
// ASMPROC_inject_before: before="lwz 0,0(11)" lines="beqlr"

struct EIFloor {
    void operator_delete();
};

void EIFloor::operator_delete() {
}
