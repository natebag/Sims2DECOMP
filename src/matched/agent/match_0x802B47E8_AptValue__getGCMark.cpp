// 0x802B47E8 AptValue::getGCMark (12b)

struct AptValue { unsigned int flags; };

int AptValue_getGCMark(AptValue* self) {
    return (self->flags >> 30) & 1;
}
