// 0x802B47E8 AptValue::getGCMark (12b)
struct AV_getGCMark { unsigned int flags; };
int AV_getGCMark_func(AV_getGCMark* self) { return (self->flags >> 30) & 1; }
