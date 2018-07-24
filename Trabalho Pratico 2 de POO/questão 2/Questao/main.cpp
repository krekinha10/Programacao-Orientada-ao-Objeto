// PROGRAMA DE TESTE DA CLASSE DATA
#include <iostream>
using std::cout;
using std::cin;
using std::boolalpha;

#include <string>
using std::string;

#include <iomanip>
using std::setw;

#include "Data.h"


int main()
{
    string f1 = "dd/mm/aaaa";
    string f2 = "mm/dd/aaaa";
    string f3 = "aaaa/mm/dd";

    Data d1;
    Data d2(f1, "06/11/2017");
    Data d3(f2, "08/23/1993");
    Data d4(f3, "2007/02/03");
    Data d5(f1, "29-02-2000");
    Data d6(f1, "13/02/1999");
    Data d7(f1, "01/01/2000");
    //Data d7(f1, "29/01/2007"); // TESTE
    //
    /////////////////////////////// PARTE 1 - OBJETOS, FORMATOS /////////////////////////////
    //
    cout << "\n 1 Instanciando objtetos, diferentes formatos de entrada e saida:"
         << "\n  1.1 formato e data default:"
         << "\n     Data d1"
         << "\n     d1.printDataNoFormato(): ";
    d1.printDataNoFormato();
    cout << "     d1.printDataPorExtenso(): ";
    d1.printDataPorExtenso();
    //
    cout << "\n  1.2 formato dd/mm/aaaa:"
         << "\n     Data d2(\"dd/mm/aaaa\", \"06/11/2017\")"
         << "\n     d2.printDataNoFormato(): ";
    d2.printDataNoFormato();
    cout << "     d2.printDataPorExtenso(): ";
    d2.printDataPorExtenso();
    //
    cout << "\n  1.3 formato mm/dd/aaaa:"
         << "\n     Data d3(\"mm/dd/aaaa\", \"08/23/1993\")"
         << "\n     d3.printDataNoFormato(): ";
    d3.printDataNoFormato();
    cout << "     d3.printDataPorExtenso(): ";
    d3.printDataPorExtenso();
    //
    cout << "\n  1.4 formato aaaa/mm/dd:"
         << "\n     Data d4(\"aaaa/mm/dd\", \"2007/02/03\")"
         << "\n     d4.printDataNoFormato(): ";
    d4.printDataNoFormato();
    cout << "     d4.printDataPorExtenso(): ";
    d4.printDataPorExtenso();
    //
    cout << "\n  1.5 Separador '-':"
         << "\n     Data d5(\"dd/mm/aaaa\", \"29-02-2000\")"
         << "\n     d5.printDataNoFormato(): ";
    d5.printDataNoFormato();
    cout << "     d5.printDataPorExtenso(): ";
    d5.printDataPorExtenso();
    //
    cout << "\n  1.6 Retornando uma data em diferentes formatos:"
         << "\n     Data d6(\"dd/mm/aaaa\", \"13/02/1999\")"
         << "\n     d5.printDataNoFormato(\"dd/mm/aaaa\"): ";
    d6.printDataNoFormato(f1);
    cout << "     d6.printDataNoFormato(\"mm/dd/aaaa\"): ";
    d6.printDataNoFormato(f2);
    cout << "     d6.printDataNoFormato(\"aaaa/mm/dd\"): ";
    d6.printDataNoFormato(f3);
    cout << "     d6.printDataPorExtenso(): ";
    d6.printDataPorExtenso();
    //
    /////////////////////////////// PARTE 2 - OPERAÇÕES COM DATAS /////////////////////////////
    //
    cout << "\n 2 Operacoes com Datas:"
         << "\n  2.1 Testa Add/SubDias(+n):"
         << "\n     Data original: ";
    d7.printDataNoFormato();
    cout << "        Add/SubDias(0): ";
    d7.AddSubDias(0);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(1): ";
    d7.AddSubDias(1);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(2): ";
    d7.AddSubDias(2);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(10): ";
    d7.AddSubDias(10);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(20): ";
    d7.AddSubDias(20);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(30): ";
    d7.AddSubDias(30);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(60): ";
    d7.AddSubDias(60);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(90): ";
    d7.AddSubDias(90);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(120): ";
    d7.AddSubDias(120);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(365): ";
    d7.AddSubDias(365);
    d7.printDataNoFormato();
    //
    cout << "\n  2.2 Testa Add/SubDias(-n):"
         << "\n     Data original: ";
    d7.printDataNoFormato();
    cout << "        Add/SubDias(0): ";
    d7.AddSubDias(0);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(-1): ";
    d7.AddSubDias(-1);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(-2): ";
    d7.AddSubDias(-2);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(-10): ";
    d7.AddSubDias(-10);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(-20): ";
    d7.AddSubDias(-20);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(-30): ";
    d7.AddSubDias(-30);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(-60): ";
    d7.AddSubDias(-60);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(-90): ";
    d7.AddSubDias(-90);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(-120): ";
    d7.AddSubDias(-120);
    d7.printDataNoFormato();
    cout << "        Add/SubDias(-365): ";
    d7.AddSubDias(-365);
    d7.printDataNoFormato();
    //
    cout << "\n  2.3 Testa Add/SubMeses(+n):"
         << "\n     Data original: ";
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(0): ";
    d7.AddSubMeses(0);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(1): ";
    d7.AddSubMeses(1);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(2): ";
    d7.AddSubMeses(2);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(3): ";
    d7.AddSubMeses(3);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(6): ";
    d7.AddSubMeses(6);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(12): ";
    d7.AddSubMeses(12);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(24): ";
    d7.AddSubMeses(24);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(36): ";
    d7.AddSubMeses(36);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(48): ";
    d7.AddSubMeses(48);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(60): ";
    d7.AddSubMeses(60);
    d7.printDataNoFormato();

    //
    cout << "\n  2.4 Testa Add/SubMeses(-n):"
         << "\n     Data original: ";
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(0): ";
    d7.AddSubMeses(0);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(-1): ";
    d7.AddSubMeses(-1);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(-2): ";
    d7.AddSubMeses(-2);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(-3): ";
    d7.AddSubMeses(-3);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(-6): ";
    d7.AddSubMeses(-6);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(-12): ";
    d7.AddSubMeses(-12);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(-24): ";
    d7.AddSubMeses(-24);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(-36): ";
    d7.AddSubMeses(-36);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(-48): ";
    d7.AddSubMeses(-48);
    d7.printDataNoFormato();
    cout << "        Add/SubMeses(-60): ";
    d7.AddSubMeses(-60);
    d7.printDataNoFormato();

    //
    cout << "\n  2.5 Testa Add/SubAnos(+n):"
         << "\n     Data original: ";
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(0): ";
    d7.AddSubAnos(0);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(1): ";
    d7.AddSubAnos(1);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(2): ";
    d7.AddSubAnos(2);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(3): ";
    d7.AddSubAnos(3);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(10): ";
    d7.AddSubAnos(10);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(20): ";
    d7.AddSubAnos(20);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(30): ";
    d7.AddSubAnos(30);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(40): ";
    d7.AddSubAnos(40);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(50): ";
    d7.AddSubAnos(50);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(100): ";
    d7.AddSubAnos(100);
    d7.printDataNoFormato();

    //
    cout << "\n  2.6 Testa Add/SubAnos(-n):"
         << "\n     Data original: ";
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(0): ";
    d7.AddSubAnos(0);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(-1): ";
    d7.AddSubAnos(-1);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(-2): ";
    d7.AddSubAnos(-2);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(-3): ";
    d7.AddSubAnos(-3);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(-10): ";
    d7.AddSubAnos(-10);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(-20): ";
    d7.AddSubAnos(-20);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(-30): ";
    d7.AddSubAnos(-30);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(-40): ";
    d7.AddSubAnos(-40);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(-50): ";
    d7.AddSubAnos(-50);
    d7.printDataNoFormato();
    cout << "        Add/SubAnos(-100): ";
    d7.AddSubAnos(-100);
    d7.printDataNoFormato();

    //
    cout << "\n  2.7 Testa DiasEntreDatas( Data &, Data & ): Retorna a diferenca, em dias, entre duas datas"
         << "\n     d1: ";
    d1.printDataNoFormato();
    cout << "     d2: ";
    d2.printDataNoFormato();
    cout << "     d3: ";
    d3.printDataNoFormato();
    cout << "     d4: ";
    d4.printDataNoFormato();
    //
    cout << "       DiasEntreDatas(d1, d2) = d1 - d2 = "
         << d1.DiasEntreDatas( d1, d2 ) << " dias" << endl;
    cout << "       DiasEntreDatas(d2, d1) = d2 - d1 = "
         << d1.DiasEntreDatas( d2, d1 ) << " dias" << endl;
    cout << "       DiasEntreDatas(d2, d3) = d2 - d3 = "
         << d1.DiasEntreDatas( d2, d3 ) << " dias" << endl;
    cout << "       DiasEntreDatas(d3, d2) = d3 - d2 = "
         << d1.DiasEntreDatas( d3, d2 ) << " dias" << endl;
    cout << "       DiasEntreDatas(d3, d4) = d3 - d4 = "
         << d1.DiasEntreDatas( d3, d4 ) << " dias" << endl;
    cout << "       DiasEntreDatas(d4, d3) = d4 - d3 = "
         << d1.DiasEntreDatas( d4, d3 ) << " dias" << endl;
    //
    /////////////////////////////// PARTE 3 - SOBRECARGA DE OPERADORES /////////////////////////////
    //
    cout << "\n 3 Sobrecarga de operadores (++, --, ==, !=, >, <, >=, <=, =, <<, >>):"
         << "\n  3.1 Testa ++data, --data, data++, data-- :\n";

    cout << "\n    ++data (operador de incremento pre-fixado):"
         << "\n        d5 is " << d5;
    cout << "\n      ++d5 is " << ++d5;
    cout << "\n        d5 is " << d5 << endl;
    //
    cout << "\n    --data (operador de decremento pre-fixado):"
         << "\n        d5 is " << d5;
    cout << "\n      --d5 is " << --d5;
    cout << "\n        d5 is " << d5 << endl;
    //
    cout << "\n    data++ (operador de incremento pos-fixado):"
         << "\n        d5 is " << d5;
    cout << "\n        d5++ is " << d5++;
    cout << "\n        d5 is " << d5 << endl;
    //
    cout << "\n    data-- (operador de decremento pos-fixado):"
         << "\n        d5 is " << d5;
    cout << "\n        d5-- is " << d5--;
    cout << "\n        d5 is " << d5 << endl;
    //
    cout << "\n  3.2 Testa ==, !=, >, <, >= e <= :";

    Data d8(f1,"15/08/1998");
    Data d9(f2,"08/15/1998");
    Data d10(f3,"1945/03/15");

    cout << "\n\n     Data d8(\"dd/mm/aaaa\",\"15/08/1998\"): ";
    d8.printDataNoFormato(f1);
    cout << "     Data d9(\"mm/dd/aaaa\",\"08/15/1998\"): ";
    d9.printDataNoFormato(f2);
    cout << "     Data d10(\"aaaa/mm/dd\",\"1945/03/15\"): ";
    d10.printDataNoFormato(f3);

    cout << boolalpha
         << "\n     d8 == d9 ? " << ( d8 == d9 )
         << "\n     d8 != d9 ? " << ( d8 != d9 )
         << "\n     d8 > d9  ? " << ( d8 > d9 )
         << "\n     d8 < d9  ? " << ( d8 < d9 )
         << "\n     d8 >= d9 ? " << ( d8 >= d9 )
         << "\n     d8 <= d9 ? " << ( d8 <= d9 );

    cout << boolalpha
         << "\n\n     d9 == d10 ? " << ( d9 == d10 )
         << "\n     d9 != d10 ? " << ( d9 != d10 )
         << "\n     d9 > d10  ? " << ( d9 > d10 )
         << "\n     d9 < d10  ? " << ( d9 < d10 )
         << "\n     d9 >= d10 ? " << ( d9 >= d10 )
         << "\n     d9 <= d10 ? " << ( d9 <= d10 ) << endl;
    //
    cout << "\n  3.3 Testa = (operador de atribuicao):";

    Data d11(f1,"10/11/1937");
    Data d12(f2,"12/15/3050");

    cout << "\n\n     Data d11(\"dd/mm/aaaa\",\"10/11/1937\"): ";
    d11.printDataNoFormato(f1);
    cout << "     Data d12(\"mm/dd/aaaa\",\"12/15/3050\"): ";
    d12.printDataNoFormato(f2);

    cout << "\n                   d11 = d12 ";
    d11 = d12;
    cout << "\n\n     d11: " << d11 << endl;
    cout << "     d12: " << d12 << endl;

    //
    cout << "\n  3.4 Testa >> (cin) e << (cout):";

    Data d13;

    cout << "\n\n   Entre com um formato (Ex: dd/mm/aaaa) e uma data (Ex: 23/08/1993), sem aspas: ";

    cin >> d13;

    cout << "\n     d13.printDataNoFormato(\"dd/mm/aaaa\"): ";
    d13.printDataNoFormato(f1);
    cout << "     d13.printDataNoFormato(\"mm/dd/aaaa\"): ";
    d13.printDataNoFormato(f2);
    cout << "     d13.printDataNoFormato(\"aaaa/mm/dd\"): ";
    d13.printDataNoFormato(f3);
    cout << "     d13.printDataPorExtenso(): ";
    d13.printDataPorExtenso();

    cout << "     cout << d13 : ";
    cout << d13
         << endl;

    return 0;
}
