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
