class CASSelectionTarget {
public:
    void ClearTextures(unsigned int start, unsigned int end);
    void ClearTextures(void);
};

void CASSelectionTarget::ClearTextures(void) {
    ClearTextures(0, 15);
}
