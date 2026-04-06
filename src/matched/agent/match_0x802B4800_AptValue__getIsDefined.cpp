// 0x802B4800 AptValue::getIsDefined (12b)

struct AptValue { unsigned int flags; };

int AptValue_getIsDefined(AptValue* self) {
    return (self->flags >> 27) & 1;
}
