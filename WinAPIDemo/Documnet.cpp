#include "Documnet.h"

void Documnet::render(const HDC& hdc) {
    render(hdc, { 0, 0 });
}

void Documnet::render(const HDC& hdc, const ViewPosition& offset){
    for (const auto& child : childs) {
        child->render(hdc, offset);
    }
}

std::list<std::shared_ptr<IView>>& Documnet::getChilds(){
    return childs;
}
