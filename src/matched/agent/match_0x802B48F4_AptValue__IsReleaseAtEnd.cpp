// 0x802B48F4 AptValue::IsReleaseAtEnd (12b)

struct AptValue { unsigned int flags; };

int AptValue_IsReleaseAtEnd(AptValue* self) {
    return (self->flags >> 29) & 1;
}
