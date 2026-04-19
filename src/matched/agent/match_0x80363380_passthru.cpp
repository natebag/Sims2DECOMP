/* EDL::Alloc(unsigned int, int) at 0x80363380 (32B) */
// 0x80363380 (32 bytes)
class EAllocGroup {
public:
    void Alloc(unsigned int size, int flags);
};
class EDL : public EAllocGroup {
public:
    void Alloc(unsigned int size, int flags);
};
void EDL::Alloc(unsigned int size, int flags) {
    EAllocGroup::Alloc(size, flags);
}
