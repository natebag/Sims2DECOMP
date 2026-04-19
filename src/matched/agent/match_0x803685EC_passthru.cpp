/* ERBinary::CreateCopy(void) at 0x803685EC (32B) */
// 0x803685EC (32 bytes)
class EStorable {
public:
    EStorable* CreateCopy() const;
};
class ERBinary : public EStorable {
public:
    ERBinary* CreateCopy() const;
};
ERBinary* ERBinary::CreateCopy() const {
    return (ERBinary*)EStorable::CreateCopy();
}
