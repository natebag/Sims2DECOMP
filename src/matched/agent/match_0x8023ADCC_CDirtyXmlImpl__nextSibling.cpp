extern int CDirtyXmlNode_nextSibling(void *self);

struct CDirtyXmlImpl {
    int nextSibling();
};

int CDirtyXmlImpl::nextSibling() {
    return CDirtyXmlNode_nextSibling(this);
}
