#include<boost/numeric/ublas/matrix.hpp>
#include<boost/numeric/ublas/io.hpp>
#include<boost/numeric/bindings/traits/ublas_matrix.hpp>
#include<boost/numeric/bindings/lapack/gesv.hpp>
#include <boost/numeric/bindings/traits/ublas_vector2.hpp>

// compileable with this command


//g++ -I/home/foolb/.boost/include/boost-1_38 -I/home/foolb/.boostnumbind/include/boost-numeric-bindings solve_Axb_byhand.cc -o solve_Axb_byhand -llapack


namespace ublas = boost::numeric::ublas;
namespace lapack= boost::numeric::bindings::lapack;


int main()
{
    ublas::matrix<float,ublas::column_major> A(3,3);
    ublas::vector<float> b(3);


    for(unsigned i=0;i < A.size1();i++)
        for(unsigned j =0;j < A.size2();j++)
        {
            std::cout << "enter element "<<i << j << std::endl;
            std::cin >> A(i,j);
        }

    std::cout << A << std::endl;

    b(0) = 21; b(1) = 1; b(2) = 17;

    lapack::gesv(A,b);

    std::cout << b << std::endl;


    return 0;
}