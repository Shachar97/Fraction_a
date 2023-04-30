#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

const int TEN = 10;

namespace ariel{

    class Fraction {

    private:
        int _numerator;
        int _denominator;
        
    public:
        /*CONSTRUCTORS*/
        Fraction(int numerator=1, int denominator=TEN);
        Fraction(const Fraction& other);//copy
        Fraction(Fraction&&) noexcept; //move constructor
        /*DESTRUCTOR*/
        ~Fraction();

    /*~~~~~~~~~~~~~~~~~~~~~
        GETTERS & SETTERS:
      ~~~~~~~~~~~~~~~~~~~~*/

        int getNumerator() const;
        int getDenominator() const;

        void setNumerator( int numerator);
        void setDenominator( int denominator);

    /*~~~~~~~~~~~~~~~~~~~
        OPERATORS:
      ~~~~~~~~~~~~~~~~~~*/

        /*DESIGNATIONS*/
        Fraction& operator= (const Fraction& other);
        Fraction& operator=(Fraction&&) noexcept;//move assignment

        /*DESIGNATIONS & ARITHMETICS*/
        Fraction& operator+= (const Fraction& other);
        Fraction& operator-= (const Fraction& other);
        Fraction& operator/= (const Fraction& other);
        Fraction& operator*= (const Fraction& other);
        
        /*INCREASE & DECREASE*/
        Fraction& operator-- ();
        Fraction operator-- (int);
        Fraction& operator++ ();
        Fraction operator++ (int);

        /*ARITHMETICS*/
        friend Fraction operator+ (const Fraction& fracL, const Fraction& fracR);

        friend Fraction operator+ (const Fraction& fraction ,const float& right_d);
        friend Fraction operator+ (const float& left_float,const Fraction& fraction);

        friend Fraction operator- (const Fraction& fracL, const Fraction& fracR);

        friend Fraction operator- (const Fraction& fraction ,const float& right_float);
        friend Fraction operator- (const float& left_float,const Fraction& fraction);

        friend Fraction operator/ (const Fraction& fracL, const Fraction& fracR);

        friend Fraction operator/ (const Fraction& fraction ,const float& right_d);
        friend Fraction operator/ (const float& left_float,const Fraction& fraction);


        friend Fraction operator* (const Fraction& fracL, const Fraction& fracR);

        friend Fraction operator* (const Fraction& fraction ,const float& right_d);
        friend Fraction operator* (const float& left_float,const Fraction& fraction);


        /*BOOLEAN*/
        friend bool operator==(const Fraction& fracL, const Fraction& fracR);
        friend bool operator!=(const Fraction& fracL, const Fraction& fracR);
        friend bool operator<(const Fraction& fracL, const Fraction& fracR);
        friend bool operator<=(const Fraction& fracL, const Fraction& fracR);
        friend bool operator>(const Fraction& fracL, const Fraction& fracR);
        friend bool operator>=(const Fraction& fracL, const Fraction& fracR);

            /*compare with float*/
        friend bool operator==(const float& left_float, const Fraction& fracR);
        friend bool operator!=(const float& left_float, const Fraction& fracR);
        friend bool operator<(const float& left_float, const Fraction& fracR);
        friend bool operator<=(const float& left_float, const Fraction& fracR);
        friend bool operator>(const float& left_float, const Fraction& fracR);
        friend bool operator>=(const float& left_float, const Fraction& fracR);

        friend bool operator==(const Fraction& fracL, const float& right_float);
        friend bool operator!=(const Fraction& fracL, const float& right_float);
        friend bool operator<(const Fraction& fracL, const float& right_float);
        friend bool operator<=(const Fraction& fracL, const float& right_float);
        friend bool operator>(const Fraction& fracL, const float& right_float);
        friend bool operator>=(const Fraction& fracL, const float& right_float);

        /*IO*/
        friend std::ostream& operator<< (std::ostream& output, const Fraction& fraction);
        friend std::istream& operator>> (std::istream& input , Fraction& fraction);
    };
    
}
#endif