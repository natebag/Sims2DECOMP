struct REffectsAttachment {
    ~REffectsAttachment();
    static void Destruct(REffectsAttachment* obj);
};

void REffectsAttachment::Destruct(REffectsAttachment* obj) {
    obj->~REffectsAttachment();
}
