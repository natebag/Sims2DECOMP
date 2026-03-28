extern int CDirtyXmlNode_getAttribute(void *self);

struct CDirtyXmlImpl {
    int getAttribute();
};

int CDirtyXmlImpl::getAttribute() {
    return CDirtyXmlNode_getAttribute(this);
}
