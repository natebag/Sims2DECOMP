// 0x802B49A8 AptValue::isXmlAttributes (24b)

struct AptValue { unsigned int flags; };

int AptValue_isXmlAttributes(AptValue* self) {
    return (self->flags & 0x7F) == 0x22;
}
