// Data.h
// INTERFACE DA CLASSE DERIVADA DATA
#ifndef DATA_H
#define DATA_H

#include <iostream>
using std::ostream;
using std::istream;

#include <string>
using std::string;

#include "DataInterface.h"

// HERAN�A P�BLICA: CLASSE DERIVADA HERDA AS FUN��ES MENBRO PUBLIC E OS MEMBROS DE DADOS PROTECTED DA CLASSE PAI DATAINTERFACE
class Data : public DataInterface
{
    friend ostream &operator<<( ostream &, const Data & );  // OPERADOR DE ENTRADA SOBRECARREGADO
    friend istream &operator>>( istream &, Data & );        // OPERADOR DE SA�DA SOBRECARREGADO

public:
    Data( string sFormato = "dd/mm/aaaa", string sData = "01/01/2000" );    // CONSTRUTOR
    ~Data();                                                                // DESTRUTOR

    // FUN��ES SET
    void setDia( int );                 // DEFINE E VALIDA O DIA (ENTRE 1 E O N�MERO DE DIAS NO M�S)
    void setMes( int );                 // DEFINE E VALIDA O M�S (ENTRE 1 E 12)
    void setAno( int );                 // DEFINE E VALIDA O ANO (ENTRE 1 E 100,000)
    void setFormato( string );          // DEFINE O FORMATO DA DATA
    void setSeparador( string );        // EXTRAI E DEFINE O SEPARADOR ( '/' OU  '-' ) DA DATA INFORMADA
    void setData( string, string );     // EXTRAI E DEFINE O DIA, M�S E O ANO DA DATA INFORMADA, USA AS FUN��ES SET, E DEFINE O FORMATO

    // FUN��ES GET
    int getDia();                       // RETORNA O DIA (VALOR INTEIRO)
    int getMes();                       // RETORNA O M�S (VALOR INTEIRO)
    int getAno();                       // RETORNA O ANO (VALOR INTEIRO)
    string getFormato();                // RETORNA O FORMATO INFORMADO NA CRIA��O DO OBJETO (STRING)
    char getSeparador();                // RETORNA O SEPARADOR '/' OU  '-' (CHAR)
    string getData();                   // RETORNA A DATA (DIA, M�S E ANO) NO FORMATO INFORMADO NA CRIA��O DO OBJETO (STRING)

    // FUN��ES AUXILIARES
    string NumberToString( int );       // CONVERTE INTEIRO PARA STRING(CONST CHAR*)
    bool AnoBissexto( int );            // VERIFICA SE O ANO � BISSEXTO (RETORNA 1(UM) SE FOR E 0(ZERO) SE N�O FOR)
    bool FimDoMes( int );               // VERIFICA SE O DIA INFORMADO � O �LTIMO DIA DE UM DETERMINADO M�S

    // OUTPUT FUNCTIONS
    void printDataNoFormato();                  // IMPRIME A DATA NA TELA, PARA O FORMATO NO QUAL FOI INSTANCIADO O OBJETO
    void printDataNoFormato( string Formato );  // FUN��O SOBRECARREGADA: IMPRIME A DATA, PARA QUALQUER FORMATO PASSADO COMO PAR�METRO
    void printDataPorExtenso();                 // IMPRIME UMA DATA NA TELA POR EXTENSO (EX: 23 DE AGOSTO DE 2007)

    // FUN��ES PARA OPERA��ES COM DATAS
    void IncrementaData();                      // INCREMENTA UMA DATA EM UM DIA E VALIDA A NOVA DATA
    void DecrementaData();                      // DECREMENTA UMA DATA EM UM DIA E VALIDA A NOVA DATA
    void AddSubDias( int Dias = 0 );            // ADD OU SUB DIAS A UMA DATA E VALIDA A NOVA DATA
    void AddSubMeses( int Meses = 0 );          // ADD OU SUB MESES A UMA DATA E VALIDA A NOVA DATA
    void AddSubAnos( int Anos = 0 );            // ADD OU SUB ANOS A UMA DATA E VALIDA A NOVA DATA
    int DiasAteAData( Data & );                 // RETORNA QUANTOS DIAS SE PASSARAM DE 1/1/0001 AT� A DATA ATUAL
    int DiasEntreDatas( Data &, Data & );       // RETORNA O N�MERO DE DIAS ENTRE DUAS DATAS

    // OPERADORES SOBRECARREGADOS
    Data &operator++();                                                         // ++Data (INCREMENTO PRE-FIXADO)
    Data operator++( int );                                                     // Data++ (INCREMENTO POS-FIXADO)
    Data &operator--();                                                         // --Data (DECREMENTO PRE-FIXADO)
    Data operator--( int );                                                     // Data-- (DECREMENTO POS-FIXADO)
    bool operator==( const Data & ) const;                                      // == (VERIFICA SE DUAS DATAS S�O IGUAIS)
    bool operator!=( const Data &Direita ) const {return !(*this == Direita);}  // != (VERIFICA SE DUAS DATAS S�O DIFERENTES)
    bool operator<( const Data & ) const;                                       // < (VERIFICA SE UMA DATA � MENOR QUE A OUTRA)
    bool operator>( const Data & ) const;                                       // > (VERIFICA SE UMA DATA � MAIOR QUE A OUTRA)
    bool operator<=( const Data &Direita ) const {return !(*this > Direita);}   // <= (VERIFICA SE UMA DATA � MENOR OU IGUAL QUE A OUTRA)
    bool operator>=( const Data &Direita ) const {return !(*this < Direita);}   // >= (VERIFICA SE UMA DATA � MAIOR OU IGUAL QUE A OUTRA)
    const Data &operator=( const Data & );                                      // = (OPERADOR DE ATRIBUI��O ENTRE DATAS)

private:
    static const int DiasEmCadaMes[];       // ARRAY STATIC QUE ARMAZENA A QUANTIDADE DE DIAS EM CADA UM DOS 12 MESES DO ANO
    static const char *MesesPorExtenso[];   // ARRAY STATIC 2D QUE ARMAZENA O NOME DE CADA UM DOS 12 MESES POR EXTENSO
};


#endif // DATA_H
