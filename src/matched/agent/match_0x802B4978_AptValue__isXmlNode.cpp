// 0x802B4978 AptValue::isXmlNode (24b)

struct AptValue { unsigned int flags; };

int AptValue_isXmlNode(AptValue* self) {
    return (self->flags & 0x7F) == 0x20;
}
