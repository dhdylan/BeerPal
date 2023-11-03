#ifndef UNITCONVERSION_H
#define UNITCONVERSION_H



enum class Unit { Milliliter, Liter, Ounce, Gallon };

class UnitConversion
{

public:

    static double MilliliterToOunce(double ml);
    static double MilliliterToLiter(double ml);
    static double MilliliterToGallon(double ml);

    static double LiterToMilliliter(double liter);
    static double LiterToOunce(double liter);
    static double LiterToGal(double liter);

    static double OunceToMilliliter(double oz);
    static double OunceToLiter(double oz);
    static double OunceToGallon(double oz);

    static double GallonToMilliliter(double gal);
    static double GallonToLiter(double gal);
    static double GallonToOunce(double gal);
};

#endif // UNITCONVERSION_H
