enum NUMBER_OF_ROOTS
{
    NO_ROOTS  = 0, //0
    ONE_ROOT = 1, //1
    TWO_ROOT = 2, //2
    INFINITY_ROOTS = 17, //17 - infinity of roots
};

struct correct_roots // structure of numbers for TestCase
{
    double a, b, c;
    int NROOTS1;
    double x1, x2;
};

// docs
//! Solves a square equation ax^2 + bx + c = 0
//! @param [in]    a a-coefficient
//! @param [in]    b b-coefficient
//! @param [in]    c c-coefficient
//! @param [out]  px1 pointer to the 1st root
//! @param [out]  px2 pointer to the 2st root
//! @return NUMBER_OF_ROOTS

int SolutionSquareEq(double a, double b, double c, double* px1, double* px2);

//! @param  [in]    a a-coefficient
//! @param  [in]    b b-coefficient
//! @return [out]   is a = b?

int Parity2Variebles(double a, double b); //check on parity 2 variebles

//! @param [in] struct
void TestCase(struct correct_roots Numbers);
//! @param i
//! @return is i = 0?
int isnul(double i);

