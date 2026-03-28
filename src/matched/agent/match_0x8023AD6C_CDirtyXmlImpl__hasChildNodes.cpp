extern int CDirtyXmlNode_hasChildNodes(void *self);

struct CDirtyXmlImpl {
    int hasChildNodes();
};

int CDirtyXmlImpl::hasChildNodes() {
    return CDirtyXmlNode_hasChildNodes(this);
}
