// 0x802B47F4 AptValue::getGCRoot (12b)
struct AV_gcr { unsigned int flags; };
int AV_gcr_func(AV_gcr* self) { return (self->flags >> 8) & 0x3F; }
