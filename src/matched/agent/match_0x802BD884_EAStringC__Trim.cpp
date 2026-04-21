// 0x802BD884 (60B) EAStringC::Trim(char *)
// Forwarding wrapper: TrimLeft(chars); TrimRight(chars).
// Saves r29 (chars) and r30 (this) via stmw to survive the first bl.

class EAStringC {
public:
    void Trim(char* chars);
    void TrimLeft(char* chars);
    void TrimRight(char* chars);
};

void EAStringC::Trim(char* chars) {
    TrimLeft(chars);
    TrimRight(chars);
}
