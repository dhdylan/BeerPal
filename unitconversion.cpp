#include "unitconversion.h"

double UnitConversion::MilliliterToOunce(double ml)
{
    return ml * 0.033814;
}

double UnitConversion::MilliliterToLiter(double ml)
{
    return ml / 1000.0;
}

double UnitConversion::MilliliterToGallon(double ml)
{
    return ml * 0.00026417;
}

double UnitConversion::LiterToMilliliter(double liter)
{
    return liter / 0.001;
}

double UnitConversion::LiterToOunce(double liter)
{
    return liter * 33.814;
}

double UnitConversion::LiterToGal(double liter)
{
    return liter * 0.26417;
}

double UnitConversion::OunceToMilliliter(double oz)
{
    return oz / 0.033814;
}

double UnitConversion::OunceToLiter(double oz)
{
    return oz / 33.814;
}

double UnitConversion::OunceToGallon(double oz)
{
    return oz * 0.0078125;
}

double UnitConversion::GallonToMilliliter(double gal)
{
    return gal / 0.00026417;
}

double UnitConversion::GallonToLiter(double gal)
{
    return gal / 0.26417;
}

double UnitConversion::GallonToOunce(double gal)
{
    return gal * 128.00;
}
