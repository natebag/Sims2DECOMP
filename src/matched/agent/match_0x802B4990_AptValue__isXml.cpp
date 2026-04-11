// 0x802B4990 AptValue::isXml (24b)
struct AV24_isXml { unsigned int flags; };
int AV24_isXml_func(AV24_isXml* self) { return (self->flags & 0x7F) == 33; }
