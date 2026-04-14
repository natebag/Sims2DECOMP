// 0x802B49D8 AptValue::isNone (24b)
struct AV24_isNone { unsigned int flags; };
int AV24_isNone_func(AV24_isNone* self) { return (self->flags & 0x7F) == 3; }
