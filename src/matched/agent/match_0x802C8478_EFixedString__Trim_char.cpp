// 0x802C8478 (64B) EFixedString::Trim(char)
// Sibling of EString::Trim — same TrimLeft+TrimRight+return *this template.

class EFixedString {
public:
    EFixedString& Trim(char c);
    EFixedString& TrimLeft(char c);
    EFixedString& TrimRight(char c);
};

EFixedString& EFixedString::Trim(char c) {
    TrimLeft(c);
    TrimRight(c);
    return *this;
}
