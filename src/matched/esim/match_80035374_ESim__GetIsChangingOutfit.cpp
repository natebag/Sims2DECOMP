// 0x80035374 (8 bytes) — lwz r3, 0x3D8(r3); blr

class ESim {
public:
    char _pad[0x3D8];
    int m_isChangingOutfit;

    int GetIsChangingOutfit();
};

int ESim::GetIsChangingOutfit() {
    return m_isChangingOutfit;
}
