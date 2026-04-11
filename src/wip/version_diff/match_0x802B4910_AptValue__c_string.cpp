// 0x802B4910 AptValue::c_string (24b)

struct AptValue {
    unsigned int flags;
    char pad[32];
    char* str;
};

char* AptValue_c_string(AptValue* self) {
    if ((self->flags & 0x7F) == 1) {
        return 0;
    }
    return self->str;
}
