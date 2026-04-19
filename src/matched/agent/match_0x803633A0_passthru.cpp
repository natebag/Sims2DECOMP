/* EDL::AllocExternal(void*, int) at 0x803633A0 (32B) */
// 0x803633A0 (32 bytes)
class ENodeList {
public:
    void AddHead(unsigned int data);
};
class EDL : public ENodeList {
public:
    void AllocExternal(void* data, int flags);
};
void EDL::AllocExternal(void* data, int) {
    ENodeList::AddHead((unsigned int)data);
}
