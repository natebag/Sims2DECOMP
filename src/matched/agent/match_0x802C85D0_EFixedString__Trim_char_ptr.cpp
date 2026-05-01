// 0x802C85D0 (64B) EFixedString::Trim(char *)
// Sibling of EString::Trim — same TrimLeft+TrimRight+return *this template.

class EFixedString {
public:
    EFixedString& Trim(const char* s);
    EFixedString& TrimLeft(const char* s);
    EFixedString& TrimRight(const char* s);
};

EFixedString& EFixedString::Trim(const char* s) {
    TrimLeft(s);
    TrimRight(s);
    return *this;
}
