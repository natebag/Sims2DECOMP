class StringBuffer {
public:
    void erase(void);
};

namespace Memory { class HandleNode; }

class QuickResFile {
public:
    void GetName(Memory::HandleNode *, StringBuffer &);
};

void QuickResFile::GetName(Memory::HandleNode *, StringBuffer &name) {
    name.erase();
}
