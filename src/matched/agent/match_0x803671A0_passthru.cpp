/* ERAmbientScore::Construct(ERAmbientScore*) at 0x803671A0 (32B) */
// 0x803671A0 (32 bytes)
class ERAmbientScore {
public:
    ERAmbientScore();
    void Construct(ERAmbientScore* other);
};
static inline void* operator new(unsigned sz, void* p) { return p; }
void ERAmbientScore::Construct(ERAmbientScore*) {
    new(this) ERAmbientScore;
}
