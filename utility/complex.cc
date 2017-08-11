/* Complex Class, by Abreto<m@abreto.net>. */

template <typename T>
struct Complex
{
    T x,y;  /* x + iy */
    Complex(void):x(T()),y(T()){}
    Complex(T xx):x(xx){}
    Complex(T xx,T yy):x(xx),y(yy){}
    inline Complex operator-(void) const {return Complex(-x,-y);}
    inline Complex operator+(const Complex& b) const {return Complex(x+b.x,y+b.y);}
    inline Complex operator-(const Complex& b) const {return Complex(x-b.x,y-b.y);}
    inline Complex operator*(const Complex& b) const {return Complex(x*b.x-y*b.y,x*b.y+y*b.x);}
    inline Complex operator/(const Complex& b) const {T bo=b.x*b.x+b.y*b.y;return Complex((x*b.x+y*b.y)/bo,(y*b.x-x*b.y)/bo);}
    inline Complex& operator+=(const Complex& b) {Complex tmp=(*this)+b;(*this)=tmp;return (*this);}
    inline Complex& operator-=(const Complex& b) {Complex tmp=(*this)-b;(*this)=tmp;return (*this);}
    inline Complex& operator*=(const Complex& b) {Complex tmp=(*this)*b;(*this)=tmp;return (*this);}
    inline Complex& operator/=(const Complex& b) {Complex tmp=(*this)/b;(*this)=tmp;return (*this);}
    inline friend Complex operator+(const T& a, const Complex& b) {return Complex(a)+b;}
    inline friend Complex operator-(const T& a, const Complex& b) {return Complex(a)-b;}
    inline friend Complex operator*(const T& a, const Complex& b) {return Complex(a)*b;}
    inline friend Complex operator/(const T& a, const Complex& b) {return Complex(a)/b;}
};
