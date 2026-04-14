// 0x802B4800 AptValue::getIsDefined (12b)
struct AV_getIsDefined { unsigned int flags; };
int AV_getIsDefined_func(AV_getIsDefined* self) { return (self->flags >> 27) & 1; }
