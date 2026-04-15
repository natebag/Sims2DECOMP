/* AptDisplayListState::GetMovieclipInfo(AptMovieclipInformation *) - 0x8029C184 (76B) */

struct AptMovieclipInformation;

struct AptCIH {
    char pad[84];
    AptCIH* m_next;  // +84 (0x54)

    void GetMovieclipInfo(AptMovieclipInformation* info);
};

class AptDisplayListState {
public:
    AptCIH* m_head;  // +0

    void GetMovieclipInfo(AptMovieclipInformation* info);
};

void AptDisplayListState::GetMovieclipInfo(AptMovieclipInformation* info) {
    AptCIH* p = m_head;
    while (p != 0) {
        p->GetMovieclipInfo(info);
        p = p->m_next;
    }
}
