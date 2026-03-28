extern int CDirtyXmlNode_previousSibling(void *self);

struct CDirtyXmlImpl {
    int previousSibling();
};

int CDirtyXmlImpl::previousSibling() {
    return CDirtyXmlNode_previousSibling(this);
}
