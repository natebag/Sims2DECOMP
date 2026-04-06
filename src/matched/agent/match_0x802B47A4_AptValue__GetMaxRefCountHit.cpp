// 0x802B47A4 AptValue::GetMaxRefCountHit (12b)

struct AptValue { unsigned int flags; };

int AptValue_GetMaxRefCountHit(AptValue* self) {
    return (self->flags >> 7) & 1;
}
