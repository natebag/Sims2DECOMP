/* ERDataset::CreateCopy(void) at 0x803698D0 (32B) */
// 0x803698D0 (32 bytes)
class EStorable {
public:
    EStorable* CreateCopy() const;
};
class ERDataset : public EStorable {
public:
    ERDataset* CreateCopy() const;
};
ERDataset* ERDataset::CreateCopy() const {
    return (ERDataset*)EStorable::CreateCopy();
}
