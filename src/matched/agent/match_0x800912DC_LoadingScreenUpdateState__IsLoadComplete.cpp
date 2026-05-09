// LoadingScreenUpdateState::IsLoadComplete(void) - 0x800912DC (52B)

struct LoadStateData {
    char _pad[0xa4];
    unsigned int m_count;
};

class LoadingScreenUpdateState {
public:
    int f0;
    int f4;
    LoadStateData* f8;
    int f12, f16, f20;
    int* f24;
    float IsLoadComplete();
};

float LoadingScreenUpdateState::IsLoadComplete()
{
    return (float)(f8->m_count);
}
