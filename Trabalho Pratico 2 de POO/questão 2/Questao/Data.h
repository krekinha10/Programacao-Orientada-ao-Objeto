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

// HERANÇA PÚBLICA: CLASSE DERIVADA HERDA AS FUNÇÕES MENBRO PUBLIC E OS MEMBROS DE DADOS PROTECTED DA CLASSE PAI DATAINTERFACE
class Data : public DataInterface
{
    friend ostream &operator<<( ostream &, const Data & );  // OPERADOR DE ENTRADA SOBRECARREGADO
    friend istream &operator>>( istream &, Data & );        // OPERADOR DE SAÍDA SOBRECARREGADO

public:
    Data( string sFormato = "dd/mm/aaaa", string sData = "01/01/2000" );    // CONSTRUTOR
    ~Data();                                                                // DESTRUTOR

    // FUNÇÕES SET
    void setDia( int );                 // DEFINE E VALIDA O DIA (ENTRE 1 E O NÚMERO DE DIAS NO MÊS)
    void setMes( int );                 // DEFINE E VALIDA O MÊS (ENTRE 1 E 12)
    void setAno( int );                 // DEFINE E VALIDA O ANO (ENTRE 1 E 100,000)
    void setFormato( string );          // DEFINE O FORMATO DA DATA
    void setSeparador( string );        // EXTRAI E DEFINE O SEPARADOR ( '/' OU  '-' ) DA DATA INFORMADA
    void setData( string, string );     // EXTRAI E DEFINE O DIA, MÊS E O ANO DA DATA INFORMADA, USA AS FUNÇÕES SET, E DEFINE O FORMATO

    // FUNÇÕES GET
    int getDia();                       // RETORNA O DIA (VALOR INTEIRO)
    int getMes();                       // RETORNA O MÊS (VALOR INTEIRO)
    int getAno();                       // RETORNA O ANO (VALOR INTEIRO)
    string getFormato();                // RETORNA O FORMATO INFORMADO NA CRIAÇÃO DO OBJETO (STRING)
    char getSeparador();                // RETORNA O SEPARADOR '/' OU  '-' (CHAR)
    string getData();                   // RETORNA A DATA (DIA, MÊS E ANO) NO FORMATO INFORMADO NA CRIAÇÃO DO OBJETO (STRING)

    // FUNÇÕES AUXILIARES
    string NumberToString( int );       // CONVERTE INTEIRO PARA STRING(CONST CHAR*)
    bool AnoBissexto( int );            // VERIFICA SE O ANO É BISSEXTO (RETORNA 1(UM) SE FOR E 0(ZERO) SE NÃO FOR)
    bool FimDoMes( int );               // VERIFICA SE O DIA INFORMADO É O ÚLTIMO DIA DE UM DETERMINADO MÊS

    // OUTPUT FUNCTIONS
    void printDataNoFormato();                  // IMPRIME A DATA NA TELA, PARA O FORMATO NO QUAL FOI INSTANCIADO O OBJETO
    void printDataNoFormato( string Formato );  // FUNÇÃO SOBRECARREGADA: IMPRIME A DATA, PARA QUALQUER FORMATO PASSADO COMO PARÂMETRO
    void printDataPorExtenso();                 // IMPRIME UMA DATA NA TELA POR EXTENSO (EX: 23 DE AGOSTO DE 2007)

    // FUNÇÕES PARA OPERAÇÕES COM DATAS
    void IncrementaData();                      // INCREMENTA UMA DATA EM UM DIA E VALIDA A NOVA DATA
    void DecrementaData();                      // DECREMENTA UMA DATA EM UM DIA E VALIDA A NOVA DATA
    void AddSubDias( int Dias = 0 );            // ADD OU SUB DIAS A UMA DATA E VALIDA A NOVA DATA
    void AddSubMeses( int Meses = 0 );          // ADD OU SUB MESES A UMA DATA E VALIDA A NOVA DATA
    void AddSubAnos( int Anos = 0 );            // ADD OU SUB ANOS A UMA DATA E VALIDA A NOVA DATA
    int DiasAteAData( Data & );                 // RETORNA QUANTOS DIAS SE PASSARAM DE 1/1/0001 ATÉ A DATA ATUAL
    int DiasEntreDatas( Data &, Data & );       // RETORNA O NÚMERO DE DIAS ENTRE DUAS DATAS

    // OPERADORES SOBRECARREGADOS
    Data &operator++();                                                         // ++Data (INCREMENTO PRE-FIXADO)
    Data operator++( int );                                                     // Data++ (INCREMENTO POS-FIXADO)
    Data &operator--();                                                         // --Data (DECREMENTO PRE-FIXADO)
    Data operator--( int );                                                     // Data-- (DECREMENTO POS-FIXADO)
    bool operator==( const Data & ) const;                                      // == (VERIFICA SE DUAS DATAS SÃO IGUAIS)
    bool operator!=( const Data &Direita ) const {return !(*this == Direita);}  // != (VERIFICA SE DUAS DATAS SÃO DIFERENTES)
    bool operator<( const Data & ) const;                                       // < (VERIFICA SE UMA DATA É MENOR QUE A OUTRA)
    bool operator>( const Data & ) const;                                       // > (VERIFICA SE UMA DATA É MAIOR QUE A OUTRA)
    bool operator<=( const Data &Direita ) const {return !(*this > Direita);}   // <= (VERIFICA SE UMA DATA É MENOR OU IGUAL QUE A OUTRA)
    bool operator>=( const Data &Direita ) const {return !(*this < Direita);}   // >= (VERIFICA SE UMA DATA É MAIOR OU IGUAL QUE A OUTRA)
    const Data &operator=( const Data & );                                      // = (OPERADOR DE ATRIBUIÇÃO ENTRE DATAS)

private:
    static const int DiasEmCadaMes[];       // ARRAY STATIC QUE ARMAZENA A QUANTIDADE DE DIAS EM CADA UM DOS 12 MESES DO ANO
    static const char *MesesPorExtenso[];   // ARRAY STATIC 2D QUE ARMAZENA O NOME DE CADA UM DOS 12 MESES POR EXTENSO
};


#endif // DATA_H
