// 0x802B49D8 AptValue::isNone (24b)

struct AptValue { unsigned int flags; };

int AptValue_isNone(AptValue* self) {
    return (self->flags & 0x7F) == 0x03;
}
