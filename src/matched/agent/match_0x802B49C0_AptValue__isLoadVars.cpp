// 0x802B49C0 AptValue::isLoadVars (24b)

struct AptValue { unsigned int flags; };

int AptValue_isLoadVars(AptValue* self) {
    return (self->flags & 0x7F) == 0x23;
}
