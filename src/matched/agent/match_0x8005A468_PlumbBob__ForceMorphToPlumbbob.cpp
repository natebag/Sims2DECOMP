/* PlumbBob::ForceMorphToPlumbbob(void) at 0x8005A468 (24B) */

class PlumbBob {
public:
    char pad[0x160];
    int m_field_160;

    void ForceMorphToPlumbbob(void);
};

void PlumbBob::ForceMorphToPlumbbob(void) {
    if (m_field_160 == 0) return;
    m_field_160 = 0;
}
