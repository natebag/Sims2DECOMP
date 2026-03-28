extern int CDirtyXmlNode_childNodes(void *self);

struct CDirtyXmlImpl {
    int childNodes();
};

int CDirtyXmlImpl::childNodes() {
    return CDirtyXmlNode_childNodes(this);
}
