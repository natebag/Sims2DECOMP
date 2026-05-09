// 0x800BB1F4 (64B) cGZMusic::getLRVolume(void)
// Convert signed int volume to float, scale by 1/1024.
// Uses standard PPC magic-number int-to-double conversion idiom.

class cGZMusic {
public:
    char _pad[20];
    int m_volume;  // +20
    float getLRVolume();
};

float cGZMusic::getLRVolume()
{
    return (float)m_volume * (1.0f / 1024.0f);
}
