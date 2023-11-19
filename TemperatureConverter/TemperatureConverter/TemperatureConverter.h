/****************************************************************************************
    Author:     Andres Trujillo
    Date:       11/18/2023
    Brief:      This program is a tool that allows you to convert between different units
                of temperature, such as Celsius, Fahrenheit, and Kelvin.
****************************************************************************************/
#pragma once

typedef enum
{
    Fahrenheit = 0,
    Celsius,
    Kelvin
}MeasurementTypes;

typedef MeasurementTypes MeasurementType;

namespace TemperatureConverter
{
    // Temperature object that stores a value and its measuring system type
    class Temperature
    {
    private:
        double value_;
        MeasurementType type_;
    public:
        // Constructor
        Temperature(double value, MeasurementType MeasureSystem);

        // Deconstructor
        ~Temperature();

        double GetValue();
        MeasurementType GetType();

        void SetValue(double newValue);
        void SetType(MeasurementType newType);

        // Converts to Fahrenheit
        Temperature GetFahrenheitConversion();

        // Converts to Celsius
        Temperature GetCelsiusConversion();

        // Converts to Kelvin
        Temperature GetKelvinConversion();
    };

    // Returns converted temperature object
    Temperature ConvertTemperatureTo(MeasurementType type, Temperature inputTemperature);
}