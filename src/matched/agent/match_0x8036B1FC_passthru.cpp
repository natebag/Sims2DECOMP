/* REffectsSequencer::CreateCopy(void) at 0x8036B1FC (32B) */
// 0x8036B1FC (32 bytes)
class EStorable {
public:
    EStorable* CreateCopy() const;
};
class REffectsSequencer : public EStorable {
public:
    REffectsSequencer* CreateCopy() const;
};
REffectsSequencer* REffectsSequencer::CreateCopy() const {
    return (REffectsSequencer*)EStorable::CreateCopy();
}
