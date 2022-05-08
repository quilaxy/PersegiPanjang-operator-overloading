#ifndef _PERSEGI_PANJANG_HPP_
#define _PERSEGI_PANJANG_HPP_

class PersegiPanjang{
    private:
        float xMin, xMax, yMin, yMax;

    public:
        PersegiPanjang(float xCenter, float yCenter, int width, int height);
        PersegiPanjang(float _xMin, float _xMax, float _yMin, float _yMax) { 
            xMin = _xMin; xMax = _xMax; yMin = _yMin; yMax = _yMax; 
            };

        void SetXMin(float value){ xMin = value; }
        void SetXMax(float value){ xMax = value; }
        void SetYMin(float value){ yMin = value; }
        void SetYMax(float value){ yMax = value; }

        float GetXMin() { return xMin; }
        float GetXMax() { return xMax; }
        float GetYMin() { return yMin; }
        float GetYMax() { return yMax; }

        int GetWidth() { return xMax - xMin; }
        int GetHeight() { return yMax - yMin; }
        float GetCenterX() { return xMin + (GetWidth() / 2.f); }
        float GetCenterY() { return yMin + (GetHeight() / 2.f); }

        bool operator==(PersegiPanjang& pp);
        PersegiPanjang operator+(PersegiPanjang& pp);
        PersegiPanjang operator-(PersegiPanjang& pp);
        PersegiPanjang& operator++();
        PersegiPanjang operator++(int);
        PersegiPanjang& operator--();
        PersegiPanjang operator--(int);
        float operator[](int index);
};

#endif