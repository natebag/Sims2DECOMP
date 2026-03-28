extern int CDirtyXmlNode_cloneNode(void *self);

struct CDirtyXmlImpl {
    int cloneNode();
};

int CDirtyXmlImpl::cloneNode() {
    return CDirtyXmlNode_cloneNode(this);
}
