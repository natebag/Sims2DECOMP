// 0x802B49C0 AptValue::isLoadVars (24b)
struct AV24_isLoadVars { unsigned int flags; };
int AV24_isLoadVars_func(AV24_isLoadVars* self) { return (self->flags & 0x7F) == 35; }
