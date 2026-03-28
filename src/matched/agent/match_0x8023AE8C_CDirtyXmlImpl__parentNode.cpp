extern int CDirtyXmlNode_parentNode(void *self);

struct CDirtyXmlImpl {
    int parentNode();
};

int CDirtyXmlImpl::parentNode() {
    return CDirtyXmlNode_parentNode(this);
}
