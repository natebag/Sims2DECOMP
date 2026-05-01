// 0x802D3AA0 (64B) EString::Trim(char)
// Calls TrimLeft(c) then TrimRight(c), returns *this. Sibling-template family with
// EFixedString::Trim variants and char* overloads.

class EString {
public:
    EString& Trim(char c);
    EString& TrimLeft(char c);
    EString& TrimRight(char c);
};

EString& EString::Trim(char c) {
    TrimLeft(c);
    TrimRight(c);
    return *this;
}
