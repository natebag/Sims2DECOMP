extern int CDirtyXmlNode_nodeName(void *self);

struct CDirtyXmlImpl {
    int nodeName();
};

int CDirtyXmlImpl::nodeName() {
    return CDirtyXmlNode_nodeName(this);
}
