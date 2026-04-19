/* EAnimNodeDataPos::Construct(EAnimNodeDataPos*) at 0x803CA8AC (32B) */
// 0x803CA8AC (32 bytes)
class EAnimNodeDataPos {
public:
    EAnimNodeDataPos();
    void Construct(EAnimNodeDataPos* other);
};
static inline void* operator new(unsigned sz, void* p) { return p; }
void EAnimNodeDataPos::Construct(EAnimNodeDataPos*) {
    new(this) EAnimNodeDataPos;
}
