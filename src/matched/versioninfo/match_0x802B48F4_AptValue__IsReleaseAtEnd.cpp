// 0x802B48F4 AptValue::IsReleaseAtEnd (12b)
struct AV_IsReleaseAtEnd { unsigned int flags; };
int AV_IsReleaseAtEnd_func(AV_IsReleaseAtEnd* self) { return (self->flags >> 29) & 1; }
