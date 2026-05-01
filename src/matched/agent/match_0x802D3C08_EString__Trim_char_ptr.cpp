// 0x802D3C08 (64B) EString::Trim(char *)
// Sibling of Trim(char): TrimLeft(s) + TrimRight(s) + return *this.

class EString {
public:
    EString& Trim(const char* s);
    EString& TrimLeft(const char* s);
    EString& TrimRight(const char* s);
};

EString& EString::Trim(const char* s) {
    TrimLeft(s);
    TrimRight(s);
    return *this;
}
