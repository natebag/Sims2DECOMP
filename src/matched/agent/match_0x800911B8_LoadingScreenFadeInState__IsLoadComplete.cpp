// LoadingScreenFadeInState::IsLoadComplete(void) - 0x800911B8 (52B)
// Returns (float)(u32) at f8->+0xa4. Emits the standard 0x4330000000000000 bias trick.

struct LoadStateData {
    char _pad[0xa4];
    unsigned int m_count;     // +0xa4
};

class LoadingScreenFadeInState {
public:
    int f0;
    int f4;
    LoadStateData* f8;        // +0x08
    int f12, f16, f20;
    int* f24;
    float IsLoadComplete();
};

float LoadingScreenFadeInState::IsLoadComplete()
{
    return (float)(f8->m_count);
}
