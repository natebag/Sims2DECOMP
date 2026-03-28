extern int CDirtyXmlNode_nodeNameHash(void *self);

struct CDirtyXmlImpl {
    int nodeNameHash();
};

int CDirtyXmlImpl::nodeNameHash() {
    return CDirtyXmlNode_nodeNameHash(this);
}
