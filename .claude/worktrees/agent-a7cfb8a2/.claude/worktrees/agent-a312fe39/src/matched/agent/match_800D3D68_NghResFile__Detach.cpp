// 0x800D3D68 (4 bytes)
class NghResFile;
namespace Memory { class HandleNode; }

namespace Memory {
class HandleNode;
}

class NghResFile {
public:
    void Detach(Memory::HandleNode *);
};

void NghResFile::Detach(Memory::HandleNode *) {}
