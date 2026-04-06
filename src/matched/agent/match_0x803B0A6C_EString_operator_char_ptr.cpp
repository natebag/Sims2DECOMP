// EString::operator char*(void) const
// Address: 0x803B0A6C | Size: 8 bytes
// Pattern: Simple field getter at offset 0 (string pointer)

struct EString {
    char* m_str;  // at offset 0
};

extern "C" char* EString_operator_char_ptr(EString* this_) {
    return this_->m_str;
}
