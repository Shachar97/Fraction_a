#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Fraction.hpp"

using namespace ariel;

/*CONSTRUCTORS*/
Fraction::Fraction(const int numerator, const int denominator):_numerator(numerator), _denominator(denominator){}

Fraction::Fraction(const Fraction& other){
    this->_numerator=other._numerator;
    this->_denominator=other._denominator;
}
Fraction::Fraction(Fraction&& other) noexcept : _numerator(other.getNumerator()),_denominator(other.getDenominator()){ //move constructor
    other.setNumerator(0);
    other.setDenominator(1);
}


/*DESTRUCTOR*/
Fraction::~Fraction(){}

/*~~~~~~~~~~~~~~~~~~~~~
    GETTERS & SETTERS:
  ~~~~~~~~~~~~~~~~~~~~*/
      
int Fraction::getNumerator() const{
    return this->_numerator;
}

int Fraction::getDenominator() const{
    return this->_denominator;
}

void Fraction::setNumerator( int numerator){
    this->_numerator=numerator;
}

void Fraction::setDenominator( int denominator){
    this->_denominator=denominator;
}

/*~~~~~~~~~~~~~~~~~~~
    OPERATORS:
  ~~~~~~~~~~~~~~~~~~*/

/*DESIGNATIONS*/
Fraction& Fraction::operator= (const Fraction& other){
    this->_numerator=other._numerator;
    this->_denominator=other._denominator;
    return *this;
}
Fraction& Fraction::operator=(Fraction&& other) noexcept{
    if(this != &other){
        this->_numerator=other.getNumerator();
        this->_denominator=other.getDenominator();
        other.setNumerator(0);
    }
    return *this;
}

/*DESIGNATIONS & ARITHMETICS*/      /*TODO ALL*/
Fraction& Fraction::operator+= (const Fraction& other){ 
    return *this;
}
Fraction& Fraction::operator-= (const Fraction& other){
    return *this;
}
Fraction& Fraction::operator/= (const Fraction& other){
    return *this;
}
Fraction& Fraction::operator*= (const Fraction& other){
    return *this;
}

/*INCREASE & DECREASE*/     /*TODO ALL*/
Fraction& Fraction::operator-- (){
    return *this;
}
Fraction Fraction::operator-- (int){
    return *this;
}
Fraction& Fraction::operator++ (){
    return *this;
}
Fraction Fraction::operator++ (int){
    return *this;
}

/*ARITHMETICS*/                 /*TODO ALL*/
Fraction ariel::operator+(const Fraction &fracL, const Fraction &fracR){
    return fracL;
}

Fraction ariel::operator+ (const Fraction& fraction ,const float& right_d){
    return fraction;
}
Fraction ariel::operator+ (const float& left_float,const Fraction& fraction){
    return fraction;
}

Fraction ariel::operator- (const Fraction& fracL, const Fraction& fracR){
    return fracL;
}

Fraction ariel::operator- (const Fraction& fraction ,const float& right_float){
    return fraction;
}
Fraction ariel::operator- (const float& left_float,const Fraction& fraction){
    return fraction;
}

Fraction ariel::operator/ (const Fraction& fracL, const Fraction& fracR){
    return fracL;
}

Fraction ariel::operator/ (const Fraction& fraction ,const float& right_d){
    return fraction;
}
Fraction ariel::operator/ (const float& left_float,const Fraction& fraction){
    return fraction;
}

Fraction ariel::operator* (const Fraction& fracL, const Fraction& fracR){
    return fracL;
}

Fraction ariel::operator* (const Fraction& fraction ,const float& right_d){
    return fraction;
}
Fraction ariel::operator* (const float& left_float,const Fraction& fraction){
    return fraction;
}

/*BOOLEAN*/                 /*TODO ALL*/
bool ariel::operator==(const Fraction& fracL, const Fraction& fracR){
    return 1;
}
bool ariel::operator!=(const Fraction& fracL, const Fraction& fracR){
    return 1;
}
bool ariel::operator<(const Fraction& fracL, const Fraction& fracR){
    return 1;
}
bool ariel::operator<=(const Fraction& fracL, const Fraction& fracR){
    return 1;
}
bool ariel::operator>(const Fraction& fracL, const Fraction& fracR){
    return 1;
}
bool ariel::operator>=(const Fraction& fracL, const Fraction& fracR){
    return 1;
}

/*compare with float*/         /*TODO ALL*/
bool ariel::operator==(const float& left_float, const Fraction& fracR){
    return 1;
}
bool ariel::operator!=(const float& left_float, const Fraction& fracR){
    return 1;
}
bool ariel::operator<(const float& left_float, const Fraction& fracR){
    return 1;
}
bool ariel::operator<=(const float& left_float, const Fraction& fracR){
    return 1;
}
bool ariel::operator>(const float& left_float, const Fraction& fracR){
    return 1;
}
bool ariel::operator>=(const float& left_float, const Fraction& fracR){
    return 1;
}

bool ariel::operator==(const Fraction& fracL, const float& right_float){
    return 1;
}
bool ariel::operator!=(const Fraction& fracL, const float& right_float){
    return 1;
}
bool ariel::operator<(const Fraction& fracL, const float& right_float){
    return 1;
}
bool ariel::operator<=(const Fraction& fracL, const float& right_float){
    return 1;
}
bool ariel::operator>(const Fraction& fracL, const float& right_float){
    return 1;
}
bool ariel::operator>=(const Fraction& fracL, const float& right_float){
    return 1;
}

/*IO*/                  /*TODO ALL*/
std::ostream& ariel::operator<< (std::ostream& output, const Fraction& fraction){
    return output;
}
std::istream& ariel::operator>> (std::istream& input , Fraction& fraction){
    return input;
}