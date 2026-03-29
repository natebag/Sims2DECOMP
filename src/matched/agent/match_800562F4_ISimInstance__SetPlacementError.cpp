// ISimInstance::SetPlacementError(bool)
// Address: 0x800562F4 | Size: 40 bytes
// Calls SetHighlight(4, bool) - r4=4 is the highlight index, r5 is the bool

class ISimInstance {
public:
    void SetHighlight(unsigned int index, bool value);
    void SetPlacementError(bool value);
};

void ISimInstance::SetPlacementError(bool value) {
    SetHighlight(4, value);
}
