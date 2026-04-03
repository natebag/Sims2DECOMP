// ObjectDataBehaviorTree::GetNumLocals (0x80226840, 112 bytes)
// Returns local variable count based on struct version checking

class ObjectDataBehaviorTree {
    char pad1[84];          // offset 0-83
    int m_resID;            // offset 84 (0x54)

public:
    short GetStructVersion() const;  // forward decl

    int GetNumLocals() const {
        short version = GetStructVersion();
        if (version >= -32766) {
            // Version -32766 or higher: read from resource data
            char *resData = (char *)m_resID;  // m_resID is actually a pointer in runtime
            return resData[6];  // offset 6 from resource data
        }
        // Version -32767
        version = GetStructVersion();
        if (version != -32767) {
            return 0;
        }
        char *resData = (char *)m_resID;
        int val = resData[6];
        if (val > 4) {
            return 4;  // clamp to 4
        }
        return val;
    }
};
