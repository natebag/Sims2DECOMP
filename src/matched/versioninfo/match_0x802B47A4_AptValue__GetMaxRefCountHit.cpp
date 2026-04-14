// 0x802B47A4 AptValue::GetMaxRefCountHit (12b)
struct AV_GetMaxRefCountHit { unsigned int flags; };
int AV_GetMaxRefCountHit_func(AV_GetMaxRefCountHit* self) { return (self->flags >> 7) & 1; }
