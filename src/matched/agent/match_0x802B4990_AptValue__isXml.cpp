// 0x802B4990 AptValue::isXml (24b)

struct AptValue { unsigned int flags; };

int AptValue_isXml(AptValue* self) {
    return (self->flags & 0x7F) == 0x21;
}
