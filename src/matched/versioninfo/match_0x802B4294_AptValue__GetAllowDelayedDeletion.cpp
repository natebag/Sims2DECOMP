// 0x802B4294 AptValue::GetAllowDelayedDeletion (12b)

struct AptValue { unsigned int flags; };

int AptValue_GetAllowDelayedDeletion(AptValue* self) {
    return (self->flags >> 26) & 1;
}
