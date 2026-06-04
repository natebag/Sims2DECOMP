// 0x802B3E78 (136B) AptValue::CanCreateScriptObject(void) const
//
// Returns 1 if the value's type tag (m_flags low 7 bits) is one of the
// script-object-capable types, else 0. A switch on a SIGNED tag (so the
// compiler lowers it into a signed cmpwi binary tree). Clean structural C++.

struct AptValue {
    unsigned int m_flags;   // 0x00
    int CanCreateScriptObject() const;
};

int AptValue::CanCreateScriptObject() const {
    int tag = m_flags & 0x7F;
    switch (tag) {
        case 1:  case 9:
        case 21: case 22:
        case 26: case 27:
        case 29: case 30:
        case 33:
        case 35: case 36:
        case 41: case 42: case 43: case 44:
            return 1;
        default:
            return 0;
    }
}
