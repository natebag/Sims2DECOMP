// 0x802B480C AptValue::setRefCount (40b)
// FLAGS: -fno-schedule-insns
typedef unsigned int uint;

struct AptValueBF {
    uint _hi : 6;
    uint refCount : 12;
    uint _lo : 14;
};

void AptValue__setRefCount(AptValueBF *self, uint count) {
    if (count > 0xFFF) {
        count = 0xFFF;
        *(uint *)self = *(uint *)self | 0x80;
    }
    self->refCount = count;
}
