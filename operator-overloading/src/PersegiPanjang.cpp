#include "include/PersegiPanjang.hpp"

PersegiPanjang::PersegiPanjang(float xCenter, float yCenter, int width, int height){
    xMin = xCenter - (width / 2.f);
    xMax = xCenter + (width / 2.f);
    yMin = yCenter - (height / 2.f);
    yMax = yCenter + (height / 2.f);
}

bool PersegiPanjang::operator==(PersegiPanjang& pp){
    bool isXIntersect = (this->GetXMin() < pp.GetXMax()) && (pp.GetXMin() < this->GetXMax());
    bool isYIntersect = (this->GetYMin() < pp.GetYMax()) && (pp.GetYMin() < this->GetYMax());
    return isXIntersect && isYIntersect;
}

PersegiPanjang PersegiPanjang::operator+(PersegiPanjang& pp){
    if(!(*this == pp)) throw;

    float new_xMin, new_xMax, new_yMin, new_yMax;

    if(this->GetXMin() < pp.GetXMin()) new_xMin = this->GetXMin();
    else new_xMin = pp.GetXMin();

    if(this->GetXMax() > pp.GetXMax()) new_xMax = this->GetXMax();
    else new_xMax = pp.GetXMax();

    if(this->GetYMin() < pp.GetYMin()) new_yMin = this->GetYMin();
    else new_yMin = pp.GetYMin();

    if(this->GetYMax() > pp.GetYMax()) new_yMax = this->GetYMax();
    else new_yMax = pp.GetYMax();

    PersegiPanjang result(new_xMin, new_xMax, new_yMin, new_yMax);

    return result;
}

PersegiPanjang PersegiPanjang::operator-(PersegiPanjang& pp){
    if(!(*this == pp)) throw;

    float new_xMin, new_xMax, new_yMin, new_yMax;

    if(this->GetXMin() > pp.GetXMin()) new_xMin = this->GetXMin();
    else new_xMin = pp.GetXMin();

    if(this->GetXMax() < pp.GetXMax()) new_xMax = this->GetXMax();
    else new_xMax = pp.GetXMax();

    if(this->GetYMin() > pp.GetYMin()) new_yMin = this->GetYMin();
    else new_yMin = pp.GetYMin();

    if(this->GetYMax() < pp.GetYMax()) new_yMax = this->GetYMax();
    else new_yMax = pp.GetYMax();

    PersegiPanjang result(new_xMin, new_xMax, new_yMin, new_yMax);

    return result;
}

PersegiPanjang& PersegiPanjang::operator++(){
    int width, height;

    width = xMax - xMin;
    height = yMax - yMin;

    xMin -= width / 2.f;
    xMax += width / 2.f;
    yMin -= height / 2.f;
    yMax += height / 2.f;

    return *this;
}

PersegiPanjang PersegiPanjang::operator++(int){
    PersegiPanjang old = *this;
    operator++();
    return old;
}

PersegiPanjang& PersegiPanjang::operator--(){
    int width, height;

    width = xMax - xMin;
    height = yMax - yMin;

    xMin += width / 4.f;
    xMax -= width / 4.f;
    yMin += height / 4.f;
    yMax -= height / 4.f;

    return *this;
}

PersegiPanjang PersegiPanjang::operator--(int){
    PersegiPanjang old = *this;
    operator--();
    return old;
}

float PersegiPanjang::operator[](int index){
    if(index % 4 == 0) return xMin;
    if(index % 4 == 1) return xMax;
    if(index % 4 == 2) return yMin;
    if(index % 4 == 3) return yMax;
}