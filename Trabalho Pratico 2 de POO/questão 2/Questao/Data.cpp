// Data.cpp
// DEFINI��ES DE FUN��ES MEMBRO DA CLASSE DERIVADA DATA
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "Data.h"

const int NumMeses = 12;

// INICIALIZA��O DO ARRAY QUE ARMAZENA A QUANTIDADE DE DIAS EM CADA M�S
const int Data::DiasEmCadaMes[NumMeses] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// INICIALIZA��O DO ARRAY QUE ARMAZENA O NOME DE CADA M�S
const char* Data::MesesPorExtenso[NumMeses] = { "Janeiro", "Fevereiro",
                    "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto",
                    "Setembro", "Outubro", "Novembro", "Dezembro" };

// IMPLEMENTA��O DO CONSTRUTOR DA CLASSE DATA
Data::Data( string sFormato, string sData )
        : DataInterface( sFormato, sData )  // CHAMA O CONSTRUTOR DA CLASSE PAI
{
    setSeparador( sData );                  // EXTRAI O TIPO DE SEPARADOR: '/' OU '-'
    setData( sFormato, sData );             // EXTRAI E DEFINE O DIA, M�S, ANO E FORMATO
}

// IMPLEMENTA��O DO DESTRUTOR DA CLASSE DATA
Data::~Data()
{
    /* empty */
}

// DEFINE E VALIDA O DIA (ENTRE 1 E O N�MERO DE DIAS NO M�S)
void Data::setDia( int Dia )
{                                                      // SE FOR FEVEREIRO (M�S 2) E
    if( getMes() == 2 && AnoBissexto( getAno() ) )     // O ANO FOR BISSEXTO: 1 <= DIA <= 29
        dia = ( Dia >= 1 && Dia <= 29 ) ? Dia : 1;     // SEN�O: 1 <= DIA <= [ 31, 28, 31, ...]
    else                                               // SE O DIA INFORMADO N�O FOR V�LIDO
        dia = ( Dia >= 1 && Dia <= DiasEmCadaMes[getMes() - 1] ) ? Dia : 1; // COLACA-SE O DIA = 1
}

// DEFINE E VALIDA O M�S (ENTRE 1 E 12)
void Data::setMes( int Mes )
{                                                       // SE 1 <= M�S <= 12, ENTRADA V�LIDA
    mes = ( Mes >= 1 && Mes <= 12 ) ? Mes : 1;          // SEN�O, SE ENTRADA INV�LIDA: M�S = 1 (JANEIRO)
}

// DEFINE E VALIDA O ANO (ENTRE 1 E 10e5)
void Data::setAno( int Ano )
{                                                       // SE 1 <= ANO <= 10e5, ENTRADA V�LIDA
    ano = ( Ano >= 1 && Ano <= 100000 ) ? Ano : 2000;   // SEN�O SE ENTRADA INV�LIDA: ANO = 2000
}

// DEFINE O FORMATO DA DATA
void Data::setFormato( string sFormato )
{
    formato = sFormato;
}

// EXTRAI E DEFINE O SEPARADOR ( '/' OU  '-' ) DA DATA INFORMADA
void Data::setSeparador( string sData )
{
    size_t i = 0;               // CONTADOR i ( DO MESMO TIPO RETORNADO POR array.size )
    char sep = '/';             // SEPARADOR PADR�O

    while ( i < sData.size() )      // ENQUANTO N�O TIVER PERCORRIDO TODOS OS CARACTERES DA STRING DATA
    {
        if ( sData[i] == '-' || sData[i] == '/' )   // VERIFICA SE O SEPARADOR � DO TIPO '/' OU '-'
        {
            sep = sData[i];                         // SE FOR, O ATRIBU�MOS A VARI�VEL sep
            //break;
        }
        i++;
    }
    separador = sep;            // ATRIBU�MOS AO MEMBRO DE DADOS separador O SEPARADOR DE DATA EXTRA�DO
}

// EXTRAI E DEFINE O DIA, M�S E O ANO DA DATA INFORMADA, USA AS FUN��ES SET, E DEFINE O FORMATO
void Data::setData( string sFormato, string sData )
{
    size_t i = 0;
    string sDia, sMes, sAno;

    while ( ( i < sData.size() ) && ( sData[i] != separador ) ) // PERCORRE A STRING DATA
    {                                                           // AT� O PRIMEIRO SEPARADOR
        sDia.push_back( sData[i] );                             // EXTRAI O VALOR NO CAMPO 'DIA'
        i++;
    }
    i++;    // INCREMENTA PARA A PRIMEIRA POSI��O NA STRING AP�S O PRIMEIRO SEPARADOR

    while ( ( i < sData.size() ) && ( sData[i] != separador ) ) // PERCORRE A STRING DATA
    {                                                           // AT� O SEGUNDO SEPARADOR
        sMes.push_back( sData[i] );                             // EXTRAI O VALOR NO CAMPO 'M�S'
        i++;
    }
    i++;    // INCREMENTA PARA A PRIMEIRA POSI��O NA STRING AP�S O SEGUNDO SEPARADOR

    while ( ( i < sData.size() ) && ( sData[i] != separador ) ) // PERCORRE A STRING DATA
    {                                                           // AT� O FIM DA STRING
        sAno.push_back( sData[i] );                             // EXTRAI O VALOR NO CAMPO 'ANO'
        i++;
    }

    // ATRIBUI OS VALORES AOS MENBRO DE DADOS DA CLASSE DE ACORDO COM O FORMATO INFORMADO PARA A DATA
    if ( sFormato[0] == 'd' )               // SE O FORMATO FOR dd/mm/aaaa
    {
        setAno( StringToNumber( sAno ) );   // CONVERTE O VALOR NA STRING sAno PARA INTEIRO E ATRIBUI AO MEMBRO DE DADOS ano
        setMes( StringToNumber( sMes ) );   // CONVERTE O VALOR NA STRING sMes PARA INTEIRO E ATRIBUI AO MEMBRO DE DADOS mes
        setDia( StringToNumber( sDia ) );   // CONVERTE O VALOR NA STRING sMes PARA INTEIRO E ATRIBUI AO MEMBRO DE DADOS dia
    }
    else if ( sFormato[0] == 'm' )          // SEN�O SE O FORMATO FOR mm/dd/aaaa (TROCAMOS O DIA COM O M�S NA HORA DE ARMAZENAR OS DADOS)
    {
        setAno( StringToNumber( sAno ) );   // CONVERTE O VALOR NA STRING sAno PARA INTEIRO E ATRIBUI AO MEMBRO DE DADOS ano
        setMes( StringToNumber( sDia ) );   // CONVERTE O VALOR NA STRING sDia PARA INTEIRO E ATRIBUI AO MEMBRO DE DADOS mes
        setDia( StringToNumber( sMes ) );   // CONVERTE O VALOR NA STRING sMes PARA INTEIRO E ATRIBUI AO MEMBRO DE DADOS dia
    }
    else if ( sFormato[0] == 'a' )          // SEN�O SE O FORMATO FOR aaaa/mm/dd (TROCAMOS O DIA COM O ANO NA HORA DE ARMAZENAR OS DADOS)
    {
        setAno( StringToNumber( sDia ) );   // CONVERTE O VALOR NA STRING sDia PARA INTEIRO E ATRIBUI AO MEMBRO DE DADOS ano
        setMes( StringToNumber( sMes ) );   // CONVERTE O VALOR NA STRING sMes PARA INTEIRO E ATRIBUI AO MEMBRO DE DADOS mes
        setDia( StringToNumber( sAno ) );   // CONVERTE O VALOR NA STRING sAno PARA INTEIRO E ATRIBUI AO MEMBRO DE DADOS dia
    }
}

// RETORNA O DIA (VALOR INTEIRO)
int Data::getDia()
{
    return dia;
}

// RETORNA O M�S (VALOR INTEIRO)
int Data::getMes()
{
    return mes;
}

// RETORNA O ANO (VALOR INTEIRO)
int Data::getAno()
{
    return ano;
}

// RETORNA O FORMATO INFORMADO NA CRIA��O DO OBJETO (STRING)
string Data::getFormato()
{
    return formato;
}

// RETORNA O SEPARADOR '/' OU  '-' (CHAR)
char Data::getSeparador()
{
    return separador;
}

// RETORNA A DATA (DIA, M�S E ANO) NO FORMATO INFORMADO NA CRIA��O DO OBJETO (STRING)
string Data::getData()
{
    string data, sep;
    string sDia, sMes, sAno;
    string sformato = getFormato();

    sep.push_back( getSeparador() );    // CONVERTE DO TIPO char PARA string E ATRIBUI A sep
    sDia = NumberToString( getDia() );  // CONVERTE O VALOR DO DIA DO TIPO int PARA string E ATRIBUI A sDia
    sMes = NumberToString( getMes() );  // CONVERTE O VALOR DO M�S DO TIPO int PARA string E ATRIBUI A sMes
    sAno = NumberToString( getAno() );  // CONVERTE O VALOR DO ANO DO TIPO int PARA string E ATRIBUI A sAno

    // FORMA UMA STRING COM A DATA DEPENDENDO DO FORMATO - UTILIZA A FUN��O append PARA FORMAR A STRING DA DATA
    if ( sformato[0] == 'd' )               // SE O FORMATO FOR dd/mm/aaaa
    {                                       // DIA + / + M�S + / + ANO = DIA/M�S/ANO
        ((((data.append( sDia )).append( sep )).append( sMes )).append( sep )).append( sAno );
    }
    else if ( sformato[0] == 'm' )          // SEN�O SE O FORMATO FOR mm/dd/aaaa
    {                                       // M�S + / + DIA + / + ANO = M�S/DIA/ANO
        ((((data.append( sMes )).append( sep )).append( sDia )).append( sep )).append( sAno );
    }
    else if ( sformato[0] == 'a' )          // SEN�O SE O FORMATO FOR aaaa/mm/dd
    {                                       // ANO + / + M�S + / + DIA = ANO/M�S/DIA
        ((((data.append( sAno )).append( sep )).append( sMes )).append( sep )).append( sDia );
    }

    return data;
}

// CONVERTE INTEIRO PARA STRING(CONST CHAR*)
string Data::NumberToString( int number )
{
    stringstream temp;      // UTILIZA A BIBLIOTECA sstream
    temp << number;
    return temp.str();
}

// VERIFICA SE O ANO � BISSEXTO (RETORNA 1(UM) SE FOR E 0(ZERO) SE N�O FOR):
//
// POR DEFINI��O, UM ANO � BISSEXTO SE ELE FOR DIVIS�VEL POR 400 (RESTO DA DIVIS�O POR 400 = 0)
// OU SE ELE FOR DIVIS�VEL POR 4 (RESTO DA DIVIS�O POR 4 = 0), MAS N�O FOR DIVIS�VEL POR 100
// (RESTO DA DIVIS�O POR 100 != 0)
bool Data::AnoBissexto( int Ano )
{
    if ( (Ano % 400 == 0) || ( (Ano % 100 != 0) && (Ano % 4 == 0) ) )
        return true;
    else
        return false;
}

// VERIFICA SE O DIA INFORMADO � O �LTIMO DIA DE UM DETERMINADO M�S
bool Data::FimDoMes( int Dia )
{       // SE O M�S ATUAL FOR FEVEREIRO (M�S 2) E O ANO ATUAL FOR BISSEXTO
    if ( getMes() == 2 && AnoBissexto( getAno() ) )
        return Dia == 29; // COMPARA O DIA INFORMADO COM O �LTIMO DIA DE FEV. PARA UM ANO BISSEXTO
    else
        return Dia == DiasEmCadaMes[getMes() - 1];  // SEN�O, COMPARA COM O �LTIMO DIA DO M�S ATUAL
}                                                   // CONTIDO NO ARRAY DiasEmCadaMes


// IMPRIME A DATA NA TELA, PARA O FORMATO NO QUAL FOI INSTANCIADO O OBJETO
void Data::printDataNoFormato()
{
    cout << getData() << endl; // IMPRIME A STRING DATA RETORNADA POR getData( ), NO FORMATO ARMAZENADO
}

// FUN��O SOBRECARREGADA: IMPRIME A DATA NA TELA, PARA QUALQUER FORMATO PASSADO COMO PAR�METRO
void Data::printDataNoFormato( string Formato )
{
    string FormatoOriginal = getFormato();  // GUARDA O FORMATO ORIGINAL
    setFormato( Formato );                  // MUDA O FORMATO DA DATA ARMAZENADA NO MEMBRO DE DADOS formato

    cout << getData( ) << endl;             // IMPRIME A STRING DATA RETORNADA POR getData( ), NO FORMATO ARMAZENADO

    setFormato( FormatoOriginal );          // REESTABELECE O FORMATO ORIGINAL DA DATA
}

// IMPRIME UMA DATA NA TELA POR EXTENSO (EX: 23 DE AGOSTO DE 2007)
void Data::printDataPorExtenso()
{                                                               // UTILIZA AS FUN��ES get PARA OBTER OS VALORES DE DIA, M�S E ANO
    cout << getDia() << " de " << MesesPorExtenso[getMes() - 1]
         << " de " << getAno() << endl;                         // E O NOME POR EXTENSO DO RESPECTIVO M�S POR MEIO DO ARRAY 2D MesesPorExtenso
}

// INCREMENTA UMA DATA EM UM DIA E VALIDA A NOVA DATA
void Data::IncrementaData()
{
    if ( !FimDoMes( getDia() ) )    // SE N�O FOR O �LTIMO DIA DO M�S
    {
        dia++;                      // INCREMENTA UM DIA
    }
    else                            // SEN�O SE ESTIVERMOS NO �LTIMO DIA DO M�S...
    {
        if ( getMes() <= 11 )       // ...E O M�S ATUAL N�O FOR O M�S 12 (�LTIMO M�S DO ANO)
        {
            mes++;                  // VIRAMOS O M�S INCREMENTANDO A VARI�VEL mes
            dia = 1;                // E ATUALIZAMOS A VARI�VEL dia PARA O PRIMEIRO DIA DO MES
        }
        else                        // ... E SE ESTIVERMOS NO �LTIMO M�S DO ANO
        {
            ano++;                  // VIRAMOS O ANO INCREMENTANDO A VARI�VEL ano
            mes = dia = 1;          // E ATUALIZAMOS O DIA E O M�S PARA O PRIMEIRO DIA DO PRIMEIRO M�S
        }
    }
}

// DECREMENTA UMA DATA EM UM DIA E VALIDA A NOVA DATA
void Data::DecrementaData()
{
    if ( getDia() > 1 )             // SE N�O FOR O PRIMEIRO DIA DO M�S
    {
        dia--;                      // DECREMENTA UM DIA
    }
    else                            // SEN�O SE ESTIVERMOS NO PRIMEIRO DIA DO M�S...
    {
        if ( getDia() <= 1 && getMes() > 1 )                    // ...E O M�S ATUAL N�O FOR JANEIRO (M�S 1)
        {
            mes--;                                              // DECREMENTA UM M�S

            if ( getMes() == 2 && AnoBissexto( getAno() ) )     // SE ESTIVERMOS NO M�S 2 (FEVEREIRO) E O ANO ATUAL FOR BISSEXTO
                dia = DiasEmCadaMes[getMes() - 1] + 1;          // O �LTIMO DIA DO M�S DE FEVEREIRO SE TORNA 28 + 1 = 29
            else
                dia = DiasEmCadaMes[getMes() - 1];              // SEN�O O �LTIMO DIA DO M�S � CONFIGURADO DE ACORDO COM A QTDE DE DIAS EM CADA M�S
        }
        else if ( getDia() <= 1 && getMes() <= 1 )              // ...E O M�S ATUAL FOR JANEIRO (M�S 1)
        {
            ano--;                                              // DECREMENTA UM ANO
            mes = 12;                                           // ATUALIZA O M�S PARA O �LTIMO M�S (M�S 12) DO NOVO ANO
            dia = DiasEmCadaMes[getMes() - 1];                  // ATUALIZA O DIA PARA O �LTIMO DIA DO �LTIMO M�S DO NOVO ANO
        }
    }
}

// ADICIONA OU SUBTRAI DIAS A UMA DATA E VALIDA A NOVA DATA
void Data::AddSubDias( int Dias )
{
    if ( Dias >= 0 )      // SE O N�MERO DE DIAS A ADICIONAR A DATA FOR MAIOR OU IGUAL A ZERO
    {
        for( int i = 0; i < Dias; i++ ) // INCREMENTA O N�MERO DE DIAS DA DATA
            IncrementaData();
    }
    else if ( Dias < 0 )  // SEN�O SE O N�MERO DE DIAS A ADICIONAR A DATA FOR MENOR QUE ZERO
    {
        for( int i = 0; i > Dias; i-- ) // DECREMENTA O N�MERO DE DIAS DA DATA
            DecrementaData();
    }
}

////////////////////////////////////////////////////////////////////////////////////////
// ADICIONA OU SUBTRAI MESES A UMA DATA E VALIDA A NOVA DATA
void Data::AddSubMeses( int Meses )
{
    int NovoAno = getAno();
    int NovoMes = getMes();
    //int NovoDia, DiaOriginal;
    //NovoDia = DiaOriginal = getDia();

    if ( Meses >= 0 )
    {
        for( int i = 0; i < Meses; i++ )
        {
            if ( NovoMes == 12 )
            {
                NovoAno++;
                NovoMes = 1;
            }
            else
            {
                NovoMes++;
            }
        }
    }
    else if ( Meses < 0 )
    {
        for( int i = 0; i > Meses; i-- )
        {
            if ( NovoMes == 1 )
            {
                NovoAno--;
                NovoMes = 12;
            }
            else
            {
                NovoMes--;
            }
        }
    }
    /*
    if( ( DiaOriginal >= 29 ) && ( !AnoBissexto(NovoAno) ) && ( NovoMes == 2 ) )
    {
        NovoDia = 28;
    }
    else if( ( DiaOriginal >= 29 ) && ( AnoBissexto(NovoAno) ) && ( NovoMes == 2 ) )
    {
        NovoDia = 29;
    }
    */
    setAno( NovoAno );
    setMes( NovoMes );
    //setDia( NovoDia );
}

////////////////////////////////////////////////////////////////////////////////////////
// ADICIONA OU SUBTRAI ANOS A UMA DATA E VALIDA A NOVA DATA
void Data::AddSubAnos( int Anos )
{
    int NovoAno = getAno();

    if ( Anos >= 0 )
    {
        for( int i = 0; i < Anos; i++ )
            NovoAno++;
    }
    else if ( Anos < 0 )
    {
        for( int i = 0; i > Anos; i-- )
            NovoAno--;
    }

    setAno( NovoAno );
}

// RETORNA QUANTOS DIAS SE PASSARAM DE 1/1/0001 AT� A DATA ATUAL
//
// ALGORITMO RATA DIE:
//      NESSE ALGORITMO, CADA ANO SE INICIA EM MAR�O E TERMINA EM FEVEREIRO.
//    MAR�O � O M�S 3 E FEVEREIRO O M�S 14. ISSO � FEITO PARA SIMPLIFICAR
//    O RELACIONAMENTO ENTRE A QUANTIDADE DE DIAS EM CADA M�S, FACILITANDO A
//    A CONTAGEM DOS DIAS. 365*ANO + ANO/4 - ANO/100 + ANO/400 FORNECE O N�MERO
//    DE DIAS AT� O COME�O DO ANO EM QUEST�O, INCLUINDO OS DIAS EXTRAS DOS ANOS
//    BISSEXTOS. (153*MES - 457)/5 � UMA APROXIMA��O LINEAR QUE CALCULA O N�MERO
//    DE DIAS NO M�S ANTERIOR. SOMAMOS A ESSAS DUAS EXPRESS�ES O DIA DO M�S ATUAL.
//    SUBTRA�MOS 306 PARA AJUSTARMOS PARA O CALEND�RIO GREGORIANO.
//    306 � O N�MERO DE DIAS ENTRE 01/03 A 31/12.
//
int Data::DiasAteAData( Data &data )
{
    int Ndias;
    int dia = data.getDia();
    int mes = data.getMes();
    int ano = data.getAno();

    // CONVERTE PARA O NOVO CALEND�RIO
    if ( mes < 3 )      // SE O M�S ATUAL FOR FEVEREIRO OU JANEIRO
    {
        ano--;          // DECREMENTA O ANO ATUAL
        mes += 12;      // E SOMA 12 MESES AO M�S ATUAL
    }                   // NOVO M�S = 13 (NOVO JAN) OU 14(NOVO FEV)

    Ndias = 365*ano + ano/4 - ano/100 + ano/400 + (153*mes - 457)/5 + dia - 306;

    return Ndias;
}


// RETORNA O N�MERO DE DIAS ENTRE DUAS DATAS
int Data::DiasEntreDatas( Data &Data1, Data &Data2 )
{                       // UTILIZA A FUN��O DiasAteAData() PARA RETORNAR O N�MERO DE DIAS...
    int Numero_dias;    // QUE SE PASSARAM DE 1/1/0001 AT� CADA UMA DAS DATAS
                        // O N�MERO DE DIAS ENTRE ESSAS DATAS � ENT�O A DIFEREN�A ENTRE
    Numero_dias = DiasAteAData( Data1 ) - DiasAteAData( Data2 ); // ESSES DOIS VALORES

    if ( Numero_dias < 0 )              // GARANTE QUE O N�MERO DE DIAS RETORNADOS SEJA POSITIVO
        Numero_dias = (-1)*Numero_dias;

    return Numero_dias;
}

// SOBRECARREGA ++Data (OPERADOR DE INCREMENTO PRE-FIXADO)
Data &Data::operator++()
{
    IncrementaData();
    return *this;
}

// SOBRECARREGA Data++ (OPERADOR DE INCREMENTO POS-FIXADO)
Data Data::operator++( int )
{
    Data temp = *this;
    IncrementaData();
    return temp;
}

// SOBRECARREGA --Data (OPERADOR DE DECREMENTO PRE-FIXADO)
Data &Data::operator--()
{
    DecrementaData();
    return *this;
}

// SOBRECARREGA Data-- (OPERADOR DE DECREMENTO POS-FIXADO)
Data Data::operator--( int )
{
    Data temp = *this;
    DecrementaData();
    return temp;
}

// SOBRECARREGA O OPERADOR DE IGUALDADE == (VERIFICA SE DUAS DATAS S�O IGUAIS)
bool Data::operator==( const Data &Direita ) const
{
    if ( (dia == Direita.dia) && (mes == Direita.mes) && (ano == Direita.ano) )
        return true;
    else
        return false;
}

// SOBRECARREGA O OPERADOR < (VERIFICA SE UMA DATA � MENOR QUE A OUTRA)
bool Data::operator<( const Data &Direita ) const
{
    bool result = false;

    if ( ano < Direita.ano )            // INICIALMENTE TESTAMOS SE O ESQUERDA.ANO < DIREITA.ANO
    {
        result = true;                  // SE SIM, RETORNA VERDADEIRO
    }
    else if ( ano == Direita.ano )      // SEN�O SE ESQUERDA.ANO FOR IGUAL A DIREITA.ANO...
    {                                   // ...N�O CONCLU�MOS NADA, DEVEMOS TESTAR O M�S DE CADA DATA
        if( mes < Direita.mes )         // ENT�O SE ESQUERDA.M�S < DIREITA.M�S
        {
            result = true;              // RETORNA VERDADEIRO
        }
        else if ( mes == Direita.mes )  // SEN�O, SE AL�M DOS ANOS, OS MESES FOREM IGUAIS...
        {                               // ...TAMB�M N�O CONCLU�MOS NADA, DEVEMOS TESTAR OS DIAS AGORA
            if ( dia < Direita.dia )    // ENT�O SE ESQUERDA.DIA < DIREITA.DIA
                result = true;          // RETORNA VERDADEIRO
            else
                result = false;         // SEN�O RETORNA FALSO
        }
    }
    else if ( ano > Direita.ano )       // POR FIM, SE ESQUERDA.ANO FOR MAIOR QUE DIREITA.ANO
    {
        result = false;                 // RETORNA FALSO: ESQUERDA.DATA N�O � MENOR QUE DIREITA.DATA
    }

    return result;
}

// SOBRECARREGA O OPERADOR > (VERIFICA SE UMA DATA � MAIOR QUE A OUTRA)
bool Data::operator>( const Data &Direita ) const
{
    bool result = false;

    if ( ano > Direita.ano )            // INICIALMENTE TESTAMOS SE O ESQUERDA.ANO > DIREITA.ANO
    {
        result = true;                  // SE SIM, RETORNA VERDADEIRO
    }
    else if ( ano == Direita.ano )      // SEN�O SE ESQUERDA.ANO FOR IGUAL A DIREITA.ANO...
    {                                   // ...N�O CONCLU�MOS NADA, DEVEMOS TESTAR O M�S DE CADA DATA
        if( mes > Direita.mes )         // ENT�O SE ESQUERDA.M�S > DIREITA.M�S
        {
            result = true;              // RETORNA VERDADEIRO
        }
        else if ( mes == Direita.mes )  // SEN�O, SE AL�M DOS ANOS, OS MESES FOREM IGUAIS...
        {                               // ...TAMB�M N�O CONCLU�MOS NADA, DEVEMOS TESTAR OS DIAS DE CADA DATA
            if ( dia > Direita.dia )    // ENT�O SE ESQUERDA.DIA > DIREITA.DIA
                result = true;          // RETORNA VERDADEIRO
            else
                result = false;         // SEN�O RETORNA FALSO
        }
    }
    else if ( ano < Direita.ano )       // POR FIM, SE ESQUERDA.ANO FOR MENOR QUE DIREITA.ANO
    {
        result = false;                 // RETORNA FALSO: ESQUERDA.DATA N�O � MAIOR QUE DIREITA.DATA
    }

    return result;
}

// SOBRECARREGA O OPERADOR DE ATRIBUI��O = (ATRIBUI��O ENTRE DATAS)
const Data &Data::operator=( const Data &Direita )
{                       // SIMPLESMENTE ATRIBU�MOS CADA MENBRO A DIREITA AO SEU RESPECTIVO MEMBRO A ESQUERDA
    dia = Direita.dia;
    mes = Direita.mes;
    ano = Direita.ano;
    formato = Direita.formato;
    separador = Direita.separador;
    return *this;
}

// SOBRECARREGA O OPERADOR DE SA�DA <<: FORNECENDO A DATA POR EXTENSO
ostream &operator<<( ostream &output, const Data &data )
{
    static string MesesPorExtenso[12] = { "Janeiro", "Fevereiro",
        "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto",
        "Setembro", "Outubro", "Novembro", "Dezembro" };

    output << data.dia << " de " << MesesPorExtenso[data.mes - 1]
         << " de " << data.ano;
    return output;
}

// SOBRECARREGA O OPERADOR DE ENTRADA >>
istream &operator>>( istream &input, Data &data )
{
    string Formato_temp, Data_temp;
    input >> Formato_temp >> Data_temp;
    data.setData( Formato_temp, Data_temp );
    return input;
}
