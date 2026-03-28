extern int CDirtyXmlNode_nodeValue(void *self);

struct CDirtyXmlImpl {
    int nodeValue();
};

int CDirtyXmlImpl::nodeValue() {
    return CDirtyXmlNode_nodeValue(this);
}
