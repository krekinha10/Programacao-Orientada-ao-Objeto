// DataInterface.h
// INTERFACE DA CLASSE ABSTRATA DataInterface
#ifndef DATAINTERFACE_H
#define DATAINTERFACE_H

#include <sstream>
#include <string>
using namespace std;


class DataInterface {

protected:
    int dia;
    int mes;
    int ano;
    string formato;         // "dd/mm/aaaa" OU "mm/dd/aaaa" ou "aaaa/mm/dd"
    char separador = '/';   // '/' OU '-'

public:
    DataInterface( string p_formato, string p_data ) // CONSTRUTOR
     : formato( p_formato )
    {
        size_t i = 0;
        string sDia, sMes, sAno;

        while ( ( i < p_data.size() ) && ( p_data[i] != separador ) )
        {
            sDia.push_back( p_data[i] );
            i++;
        }
        dia = StringToNumber( sDia );
        i++;

        while ( ( i < p_data.size() ) && ( p_data[i] != separador ) )
        {
            sMes.push_back( p_data[i] );
            i++;
        }
        mes = StringToNumber( sMes );
        i++;

        while ( ( i < p_data.size() ) && ( p_data[i] != separador ) )
        {
            sAno.push_back( p_data[i] );
            i++;
        }
        ano = StringToNumber( sAno );
    }

    ~DataInterface() { /* empty */ }; // DESTRUTOR
    virtual string getData() = 0;
    //
    // FUNÇÃO int stoi(string) SUBSTITUÍDA POR int StringToNumber(string)
    // QUE REALIZA A MESMA FUNÇÃO.
    // POIS stoi(string) NÃO ESTÁ DISPONÍVEL PARA COMPILADORES CUJA VERSÃO
    // SEJA ANTERIOR A C++11
    //
    int StringToNumber( string phrase )
    {
        istringstream buffer(phrase); // UTILIZA A BIBLIOTECA sstream
        int value;
        buffer >> value;
        return value;
    }
};


#endif // DATAINTERFACE_H
