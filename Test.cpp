#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace ariel;
using namespace std;

const size_t LOOP=1000;

//this case check that the parameters of the game had set before the game begin

TEST_CASE("CONSTRUCTORS & GETTERS"){

    Fraction a(5,3);

    Fraction b;
    Fraction c(a);

    CHECK(&c != &a);

    CHECK(a.getNumerator() == 5);
    CHECK(a.getDenominator() == 3);

    CHECK(b.getNumerator() == 1);
    CHECK(b.getDenominator() == 10);

    CHECK(c.getNumerator() == 5);
    CHECK(c.getDenominator() == 3);


}


TEST_CASE("SETTERS"){

    Fraction a(5,3);

    for(size_t i=0;i<LOOP;i++){// gcd call only in arithmetic operation

        a.setNumerator(i);
        a.setDenominator(i+1);

        CHECK(a.getNumerator() == i);
        CHECK(a.getDenominator() == i+1);
    }
}

TEST_CASE("OPERATORS: PLACEMENT"){

    Fraction a(5,3);

    // Fraction b();
    Fraction b=a;


    CHECK(a.getNumerator() == 5);
    CHECK(a.getDenominator() == 3);

    CHECK(b.getNumerator() == 5);
    CHECK(b.getDenominator() == 3);

    CHECK(&b != &a);
}


TEST_CASE("INCREACE & DECREACE"){
    Fraction a(5,3);
    Fraction b(5,3);
    
    for(size_t i =1 ; i<LOOP ; i++){

        b=a++; // (5 + i*3) / 3
        CHECK(a.getNumerator() == 5 + (i*3) );
        CHECK(a.getDenominator() == 3);
        CHECK(b.getNumerator() == 5 + ((i-1)*3) );
        CHECK(b.getDenominator() ==3);
        
    }

    a.setNumerator(5);
    a.setDenominator(3);

    for(size_t i =1 ; i<LOOP ; i++){

        b = ++a;
        CHECK(a.getNumerator() == 5 + (i*3) );
        CHECK(a.getDenominator() == 3);
        CHECK(b.getNumerator() == 5 + (i*3) );
        CHECK(b.getDenominator() ==3);

    }

    a.setNumerator(5);
    a.setDenominator(3);

    for(size_t i =1 ; i<LOOP ; i++){

        b=a--; // (5 - i*3) / 3
        CHECK(a.getNumerator() == 5 - (i*3) );
        CHECK(a.getDenominator() == 3);
        CHECK(b.getNumerator() == 5 - ((i-1)*3) );
        CHECK(b.getDenominator() ==3);
        
    }

    a.setNumerator(5);
    a.setDenominator(3);

    for(size_t i =1 ; i<LOOP ; i++){

        b = --a;
        CHECK(a.getNumerator() == 5 - (i*3) );
        CHECK(a.getDenominator() == 3);
        CHECK(b.getNumerator() == 5 - (i*3) );
        CHECK(b.getDenominator() ==3);
        
    }

}

TEST_CASE("ARITHMETIC OP: +,- between Fractions"){
    Fraction a(5,3);
    Fraction b(3,5);

    Fraction c = a+b; //5/3 + 3/5 = 34/15

    CHECK(c.getNumerator() == 34);
    CHECK(c.getDenominator() == 15);

    c += a; // 34/15 + 5/3 = 59/15

    CHECK(c.getNumerator() == 59); 
    CHECK(c.getDenominator() == 15);

    c -= a; // 8/3 - 5/3 =3/3

    CHECK(c.getNumerator() == 34); 
    CHECK(c.getDenominator() == 15);

    c= a-b; // 5/3 - 3/5 = 16/15

    CHECK(c.getNumerator() == 16); 
    CHECK(c.getDenominator() == 15);
}

TEST_CASE("ARITHMETIC OP: +,- between Fraction and float types"){
    Fraction a(5,3);
    float b = 1.666;

    Fraction c = a+b; // 5/3 + 1.666 = 4999/1500

    CHECK(c.getNumerator() == 4999);
    CHECK(c.getDenominator() == 1500);
    c = b+a; //same
    CHECK(c.getNumerator() == 4999);
    CHECK(c.getDenominator() == 1500);


    c += b; // 4999/1500 + 1.666 = 3749/750

    CHECK(c.getNumerator() == 3749); 
    CHECK(c.getDenominator() == 750);

    // b=0.6;
    c = a-b; // 5/3 - (frac)1.6 = 5/3 - 833/500 = 1/1500 

    CHECK(c.getNumerator() == 1); 
    CHECK(c.getDenominator() == 1500);

    c -= b; // 1/1500 - (frac)1.666 = 1/1500 - 2499/1500= -(2498/1500)= -(1249/750)

    CHECK(c.getNumerator() == -1249); 
    CHECK(c.getDenominator() == 750);

}

TEST_CASE("ARITHMETIC OP: *,/ between Fractions"){
    Fraction a(5,3);
    Fraction b(3,5);

    Fraction c = a*a; // 5/3 * 5/3 = 25/9

    CHECK(c.getNumerator() == 25);
    CHECK(c.getDenominator() == 9);

    c *= b; // 25/9 * 3/5 = 5/3

    CHECK(c.getNumerator() == 5); 
    CHECK(c.getDenominator() == 3);

    c = a/b; // 5/3 / 3/5 = 25/9

    CHECK(c.getNumerator() == 25); 
    CHECK(c.getDenominator() == 9);

    c /= a; // 25/9 / 5/3 = 5/3

    CHECK(c.getNumerator() == 5); 
    CHECK(c.getDenominator() == 3);

}

TEST_CASE("ARITHMETIC OP: *,/ between Fraction and float types"){
    Fraction a(5,3);
    float b = 1.666;

    Fraction c = a*b; // 5/3 * 1.666 = 833/300

    CHECK(c.getNumerator() == 833);
    CHECK(c.getDenominator() == 300);
    c = b*a; //same
    CHECK(c.getNumerator() == 833);
    CHECK(c.getDenominator() == 300);


    c *= b; // 833/300 * (fraction)1.666 = 833/300 * 833/500 = 693889/150000 ->float -> 37/8

    CHECK(c.getNumerator() == 37); 
    CHECK(c.getDenominator() == 8);

    c = a/b; // 5/3 / (fraction)1.666 = 2500/2499

    CHECK(c.getNumerator() == 2500); 
    CHECK(c.getDenominator() == 2499);

    c /= b; // 2500/2499 / (fraction)1.666 = 2500/2499 / 833/500 = (float) 0.6004.. ~ 3/5

    CHECK(c.getNumerator() == 3); 
    CHECK(c.getDenominator() == 5);

}

TEST_CASE("BOOLEAN OP: compare between Fractions"){
    Fraction a(5,3);
    Fraction b=a;

    CHECK(&a != &b);

    CHECK((a == b) == 1 );
    CHECK((a >= b) == 1 );
    CHECK((a <= b) == 1 );
    CHECK((a >= b) == 1 );

    CHECK((a > b) == 0 );
    CHECK((a < b) == 0 );
    CHECK((a != b) == 0 );

    b.setNumerator(3);
    b.setDenominator(5);

    CHECK((a == b) == 0 );
    CHECK((a >= b) == 1 );
    CHECK((a <= b) == 0 );
    CHECK((a >= b) == 1 );
    CHECK((a > b) == 1 );
    CHECK((a < b) == 0 );
    CHECK((a != b) == 1 );

    b.setNumerator(10);
    b.setDenominator(6);

    CHECK((a == b) == 1 );
    CHECK((a >= b) == 1 );
    CHECK((a <= b) == 1 );
    CHECK((a >= b) == 1 );

    CHECK((a > b) == 0 );
    CHECK((a < b) == 0 );
    CHECK((a != b) == 0 );
}

TEST_CASE("BOOLEAN OP: compare between Fractions and float types"){
    Fraction a(5,10);
    float b=1.5;

    //right
    CHECK((a == b) == 1 );
    CHECK((a >= b) == 1 );
    CHECK((a <= b) == 1 );
    CHECK((a >= b) == 1 );

    CHECK((a > b) == 0 );
    CHECK((a < b) == 0 );
    CHECK((a != b) == 0 );

    //left
    CHECK((b == a) == 1 );
    CHECK((b >= a) == 1 );
    CHECK((b <= a) == 1 );
    CHECK((b >= a) == 1 );

    CHECK((b > a) == 0 );
    CHECK((b < a) == 0 );
    CHECK((b != a) == 0 );

    b=0.6;

    //right
    CHECK((a == b) == 0 );
    CHECK((a >= b) == 1 );
    CHECK((a <= b) == 0 );
    CHECK((a >= b) == 1 );
    CHECK((a > b) == 1 );
    CHECK((a < b) == 0 );
    CHECK((a != b) == 1 );

    //left
    CHECK((b == a) == 0 );
    CHECK((b >= a) == 0 );
    CHECK((b <= a) == 1 );
    CHECK((b >= a) == 0 );
    CHECK((b > a) == 0 );
    CHECK((b < a) == 1 );
    CHECK((b != a) == 1 );

}

TEST_CASE("OPERATORS: ostream"){

    Fraction a(5,3);

    ostringstream output;
    output << a;
    CHECK(output.str() == "5/3");

}

TEST_CASE("OPERATORS: istream"){

    Fraction a;
    istringstream input("5 3");
    input >> a;
    CHECK(a.getNumerator() == 5);
    CHECK(a.getDenominator() == 3);
}

TEST_CASE("EXCEPTIONS THROW: constructor with invalid argument") {
    CHECK_THROWS_AS(Fraction(1,0), invalid_argument);
    // CHECK_THROWS_AS(Fraction(1.2,1), invalid_argument);
    // CHECK_THROWS_AS(Fraction(1,1.2), invalid_argument);
}
