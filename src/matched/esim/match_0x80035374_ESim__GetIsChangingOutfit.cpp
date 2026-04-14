// 0x80035374 ESim::GetIsChangingOutfit (8B)

struct ESim_GetIsChangingOutfit {
    char pad[0x3D8];
    int m_val;
    int GetIsChangingOutfit();
};

int ESim_GetIsChangingOutfit::GetIsChangingOutfit() {
    return m_val;
}
