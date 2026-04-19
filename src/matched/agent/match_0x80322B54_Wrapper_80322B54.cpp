/* REffectsAttachment::CreateCopy(void) at 0x80322B54 (32B) */
// 0x80322B54 (32 bytes)
class EStorable {
public:
    EStorable* CreateCopy() const;
};
class REffectsAttachment : public EStorable {
public:
    REffectsAttachment* CreateCopy() const;
};
REffectsAttachment* REffectsAttachment::CreateCopy() const {
    return (REffectsAttachment*)EStorable::CreateCopy();
}
