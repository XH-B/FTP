#ifndef DATA_H
#define DATA_H


class Data{
public:
    Data();
    Data(double ix=0,double iy=0):xx(ix),yy(iy){}
    ~Data();
    double xx;
    double yy;

};

#endif // DATA_H
