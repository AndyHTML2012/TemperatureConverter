/****************************************************************************************
    Author:     Andres Trujillo
    Date:       11/18/2023
    Brief:      This program is a tool that allows you to convert between different units
                of temperature, such as Celsius, Fahrenheit, and Kelvin.
****************************************************************************************/

#include "pch.h"
#include "TemperatureConverter.h"

using namespace TemperatureConverter;

/////////////////////////////////////////////////////////////////////
// STATIC FUNCTIONS
/////////////////////////////////////////////////////////////////////

static double CelsiusToKelvin(double Celsius)
{
    double Kelvin = Celsius + 273.15;
    return Kelvin;
}

static double CelsiusToFahrenheit(double Celsius)
{
    double Fahrenheit = (Celsius * 9.0 / 5.0) + 32.0;
    return Fahrenheit;
}

static double FahrenheitToKelvin(double Fahrenheit)
{
    double Kelvin = (Fahrenheit + 459.67) * 5.0 / 9.0;;
    return Kelvin;
}

static double FahrenheitToCelsius(double Fahrenheit)
{
    double Celsius = (Fahrenheit - 32.0) * 5.0 / 9.0;;
    return Celsius;
}

static double KelvinToCelsius(double Kelvin)
{
    double Celsius = Kelvin - 273.15;;
    return Celsius;
}

static double KelvinToFahrenheit(double Kelvin)
{
    double Fahrenheit = (Kelvin - 273.15) * 9.0 / 5.0 + 32.0;
    return Fahrenheit;
}

/////////////////////////////////////////////////////////////////////
// PUBLIC FUNCTIONS
/////////////////////////////////////////////////////////////////////

Temperature::Temperature(double value, MeasurementType MeasureSystem)
{
    value_ = value;
    type_ = MeasureSystem;
}

Temperature::~Temperature()
{
    // nothing to deconstruct
}

double Temperature::GetValue()
{
    return value_;
}

MeasurementType Temperature::GetType()
{
    return type_;
}

void Temperature::SetValue(double newValue)
{
    value_ = newValue;
}

void Temperature::SetType(MeasurementType newType)
{
    type_ = newType;
}

Temperature Temperature::GetFahrenheitConversion()
{
    Temperature FahrenheitTemp(0.0, Fahrenheit);

    MeasurementType conversionFrom = type_;

    switch (conversionFrom)
    {
    case Celsius:
    {
        double cFahrenheit = CelsiusToFahrenheit(value_);
        FahrenheitTemp.SetValue(cFahrenheit);
    }
    break;

    case Kelvin:
    {
        double kFahrenheit = KelvinToFahrenheit(value_);
        FahrenheitTemp.SetValue(kFahrenheit);
    }
    break;

    case Fahrenheit:
        FahrenheitTemp.SetValue(value_);
        break;

    default:
        break;
    }

    return FahrenheitTemp;
}

Temperature Temperature::GetCelsiusConversion()
{
    Temperature CelsiusTemp(0.0, Celsius);

    MeasurementType conversionFrom = type_;

    switch (conversionFrom)
    {
    case Celsius:
        CelsiusTemp.SetValue(value_);
        break;

    case Kelvin:
    {
        double kCelsius = KelvinToCelsius(value_);
        CelsiusTemp.SetValue(kCelsius);
    }
    break;

    case Fahrenheit:
    {
        double fCelsius = FahrenheitToCelsius(value_);
        CelsiusTemp.SetValue(fCelsius);
    }
    break;

    default:
        break;
    }

    return CelsiusTemp;
}

Temperature Temperature::GetKelvinConversion()
{
    Temperature KelvinTemp(0.0, Kelvin);

    MeasurementType conversionFrom = type_;

    switch (conversionFrom)
    {
    case Celsius:
    {
        double cKelvin = CelsiusToKelvin(value_);
        KelvinTemp.SetValue(cKelvin);
    }
    break;

    case Kelvin:
        KelvinTemp.SetValue(value_);
        break;

    case Fahrenheit:
    {
        double fKelvin = FahrenheitToKelvin(value_);
        KelvinTemp.SetValue(fKelvin);
    }
    break;

    default:
        break;
    }

    return KelvinTemp;
}

Temperature TemperatureConverter::ConvertTemperatureTo(MeasurementType type, Temperature inputTemperature)
{
    Temperature convertedTemperature(0.0, type);

    //MeasurementType inputTempType = inputTemperature.GetType();

    switch (type)
    {
    case Fahrenheit:
        convertedTemperature = inputTemperature.GetFahrenheitConversion();
        break;

    case Celsius:
        convertedTemperature = inputTemperature.GetCelsiusConversion();
        break;

    case Kelvin:
        convertedTemperature = inputTemperature.GetKelvinConversion();
        break;

    default:
        break;
    }

    return convertedTemperature;
}