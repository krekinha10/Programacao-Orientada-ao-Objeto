// Data.cpp
// DEFINIÇÕES DE FUNÇÕES MEMBRO DA CLASSE DERIVADA DATA
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "Data.h"

const int NumMeses = 12;

// INICIALIZAÇÃO DO ARRAY QUE ARMAZENA A QUANTIDADE DE DIAS EM CADA MÊS
const int Data::DiasEmCadaMes[NumMeses] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// INICIALIZAÇÃO DO ARRAY QUE ARMAZENA O NOME DE CADA MÊS
const char* Data::MesesPorExtenso[NumMeses] = { "Janeiro", "Fevereiro",
                    "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto",
                    "Setembro", "Outubro", "Novembro", "Dezembro" };

// IMPLEMENTAÇÃO DO CONSTRUTOR DA CLASSE DATA
Data::Data( string sFormato, string sData )
        : DataInterface( sFormato, sData )  // CHAMA O CONSTRUTOR DA CLASSE PAI
{
    setSeparador( sData );                  // EXTRAI O TIPO DE SEPARADOR: '/' OU '-'
    setData( sFormato, sData );             // EXTRAI E DEFINE O DIA, MÊS, ANO E FORMATO
}

// IMPLEMENTAÇÃO DO DESTRUTOR DA CLASSE DATA
Data::~Data()
{
    /* empty */
}

// DEFINE E VALIDA O DIA (ENTRE 1 E O NÚMERO DE DIAS NO MÊS)
void Data::setDia( int Dia )
{                                                      // SE FOR FEVEREIRO (MÊS 2) E
    if( getMes() == 2 && AnoBissexto( getAno() ) )     // O ANO FOR BISSEXTO: 1 <= DIA <= 29
        dia = ( Dia >= 1 && Dia <= 29 ) ? Dia : 1;     // SENÃO: 1 <= DIA <= [ 31, 28, 31, ...]
    else                                               // SE O DIA INFORMADO NÃO FOR VÁLIDO
        dia = ( Dia >= 1 && Dia <= DiasEmCadaMes[getMes() - 1] ) ? Dia : 1; // COLACA-SE O DIA = 1
}

// DEFINE E VALIDA O MÊS (ENTRE 1 E 12)
void Data::setMes( int Mes )
{                                                       // SE 1 <= MÊS <= 12, ENTRADA VÁLIDA
    mes = ( Mes >= 1 && Mes <= 12 ) ? Mes : 1;          // SENÃO, SE ENTRADA INVÁLIDA: MÊS = 1 (JANEIRO)
}

// DEFINE E VALIDA O ANO (ENTRE 1 E 10e5)
void Data::setAno( int Ano )
{                                                       // SE 1 <= ANO <= 10e5, ENTRADA VÁLIDA
    ano = ( Ano >= 1 && Ano <= 100000 ) ? Ano : 2000;   // SENÃO SE ENTRADA INVÁLIDA: ANO = 2000
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
    char sep = '/';             // SEPARADOR PADRÃO

    while ( i < sData.size() )      // ENQUANTO NÃO TIVER PERCORRIDO TODOS OS CARACTERES DA STRING DATA
    {
        if ( sData[i] == '-' || sData[i] == '/' )   // VERIFICA SE O SEPARADOR É DO TIPO '/' OU '-'
        {
            sep = sData[i];                         // SE FOR, O ATRIBUÍMOS A VARIÁVEL sep
            //break;
        }
        i++;
    }
    separador = sep;            // ATRIBUÍMOS AO MEMBRO DE DADOS separador O SEPARADOR DE DATA EXTRAÍDO
}

// EXTRAI E DEFINE O DIA, MÊS E O ANO DA DATA INFORMADA, USA AS FUNÇÕES SET, E DEFINE O FORMATO
void Data::setData( string sFormato, string sData )
{
    size_t i = 0;
    string sDia, sMes, sAno;

    while ( ( i < sData.size() ) && ( sData[i] != separador ) ) // PERCORRE A STRING DATA
    {                                                           // ATÉ O PRIMEIRO SEPARADOR
        sDia.push_back( sData[i] );                             // EXTRAI O VALOR NO CAMPO 'DIA'
        i++;
    }
    i++;    // INCREMENTA PARA A PRIMEIRA POSIÇÃO NA STRING APÓS O PRIMEIRO SEPARADOR

    while ( ( i < sData.size() ) && ( sData[i] != separador ) ) // PERCORRE A STRING DATA
    {                                                           // ATÉ O SEGUNDO SEPARADOR
        sMes.push_back( sData[i] );                             // EXTRAI O VALOR NO CAMPO 'MÊS'
        i++;
    }
    i++;    // INCREMENTA PARA A PRIMEIRA POSIÇÃO NA STRING APÓS O SEGUNDO SEPARADOR

    while ( ( i < sData.size() ) && ( sData[i] != separador ) ) // PERCORRE A STRING DATA
    {                                                           // ATÉ O FIM DA STRING
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
    else if ( sFormato[0] == 'm' )          // SENÃO SE O FORMATO FOR mm/dd/aaaa (TROCAMOS O DIA COM O MÊS NA HORA DE ARMAZENAR OS DADOS)
    {
        setAno( StringToNumber( sAno ) );   // CONVERTE O VALOR NA STRING sAno PARA INTEIRO E ATRIBUI AO MEMBRO DE DADOS ano
        setMes( StringToNumber( sDia ) );   // CONVERTE O VALOR NA STRING sDia PARA INTEIRO E ATRIBUI AO MEMBRO DE DADOS mes
        setDia( StringToNumber( sMes ) );   // CONVERTE O VALOR NA STRING sMes PARA INTEIRO E ATRIBUI AO MEMBRO DE DADOS dia
    }
    else if ( sFormato[0] == 'a' )          // SENÃO SE O FORMATO FOR aaaa/mm/dd (TROCAMOS O DIA COM O ANO NA HORA DE ARMAZENAR OS DADOS)
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

// RETORNA O MÊS (VALOR INTEIRO)
int Data::getMes()
{
    return mes;
}

// RETORNA O ANO (VALOR INTEIRO)
int Data::getAno()
{
    return ano;
}

// RETORNA O FORMATO INFORMADO NA CRIAÇÃO DO OBJETO (STRING)
string Data::getFormato()
{
    return formato;
}

// RETORNA O SEPARADOR '/' OU  '-' (CHAR)
char Data::getSeparador()
{
    return separador;
}

// RETORNA A DATA (DIA, MÊS E ANO) NO FORMATO INFORMADO NA CRIAÇÃO DO OBJETO (STRING)
string Data::getData()
{
    string data, sep;
    string sDia, sMes, sAno;
    string sformato = getFormato();

    sep.push_back( getSeparador() );    // CONVERTE DO TIPO char PARA string E ATRIBUI A sep
    sDia = NumberToString( getDia() );  // CONVERTE O VALOR DO DIA DO TIPO int PARA string E ATRIBUI A sDia
    sMes = NumberToString( getMes() );  // CONVERTE O VALOR DO MÊS DO TIPO int PARA string E ATRIBUI A sMes
    sAno = NumberToString( getAno() );  // CONVERTE O VALOR DO ANO DO TIPO int PARA string E ATRIBUI A sAno

    // FORMA UMA STRING COM A DATA DEPENDENDO DO FORMATO - UTILIZA A FUNÇÃO append PARA FORMAR A STRING DA DATA
    if ( sformato[0] == 'd' )               // SE O FORMATO FOR dd/mm/aaaa
    {                                       // DIA + / + MÊS + / + ANO = DIA/MÊS/ANO
        ((((data.append( sDia )).append( sep )).append( sMes )).append( sep )).append( sAno );
    }
    else if ( sformato[0] == 'm' )          // SENÃO SE O FORMATO FOR mm/dd/aaaa
    {                                       // MÊS + / + DIA + / + ANO = MÊS/DIA/ANO
        ((((data.append( sMes )).append( sep )).append( sDia )).append( sep )).append( sAno );
    }
    else if ( sformato[0] == 'a' )          // SENÃO SE O FORMATO FOR aaaa/mm/dd
    {                                       // ANO + / + MÊS + / + DIA = ANO/MÊS/DIA
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

// VERIFICA SE O ANO É BISSEXTO (RETORNA 1(UM) SE FOR E 0(ZERO) SE NÃO FOR):
//
// POR DEFINIÇÃO, UM ANO É BISSEXTO SE ELE FOR DIVISÍVEL POR 400 (RESTO DA DIVISÃO POR 400 = 0)
// OU SE ELE FOR DIVISÍVEL POR 4 (RESTO DA DIVISÃO POR 4 = 0), MAS NÃO FOR DIVISÍVEL POR 100
// (RESTO DA DIVISÃO POR 100 != 0)
bool Data::AnoBissexto( int Ano )
{
    if ( (Ano % 400 == 0) || ( (Ano % 100 != 0) && (Ano % 4 == 0) ) )
        return true;
    else
        return false;
}

// VERIFICA SE O DIA INFORMADO É O ÚLTIMO DIA DE UM DETERMINADO MÊS
bool Data::FimDoMes( int Dia )
{       // SE O MÊS ATUAL FOR FEVEREIRO (MÊS 2) E O ANO ATUAL FOR BISSEXTO
    if ( getMes() == 2 && AnoBissexto( getAno() ) )
        return Dia == 29; // COMPARA O DIA INFORMADO COM O ÚLTIMO DIA DE FEV. PARA UM ANO BISSEXTO
    else
        return Dia == DiasEmCadaMes[getMes() - 1];  // SENÃO, COMPARA COM O ÚLTIMO DIA DO MÊS ATUAL
}                                                   // CONTIDO NO ARRAY DiasEmCadaMes


// IMPRIME A DATA NA TELA, PARA O FORMATO NO QUAL FOI INSTANCIADO O OBJETO
void Data::printDataNoFormato()
{
    cout << getData() << endl; // IMPRIME A STRING DATA RETORNADA POR getData( ), NO FORMATO ARMAZENADO
}

// FUNÇÃO SOBRECARREGADA: IMPRIME A DATA NA TELA, PARA QUALQUER FORMATO PASSADO COMO PARÂMETRO
void Data::printDataNoFormato( string Formato )
{
    string FormatoOriginal = getFormato();  // GUARDA O FORMATO ORIGINAL
    setFormato( Formato );                  // MUDA O FORMATO DA DATA ARMAZENADA NO MEMBRO DE DADOS formato

    cout << getData( ) << endl;             // IMPRIME A STRING DATA RETORNADA POR getData( ), NO FORMATO ARMAZENADO

    setFormato( FormatoOriginal );          // REESTABELECE O FORMATO ORIGINAL DA DATA
}

// IMPRIME UMA DATA NA TELA POR EXTENSO (EX: 23 DE AGOSTO DE 2007)
void Data::printDataPorExtenso()
{                                                               // UTILIZA AS FUNÇÕES get PARA OBTER OS VALORES DE DIA, MÊS E ANO
    cout << getDia() << " de " << MesesPorExtenso[getMes() - 1]
         << " de " << getAno() << endl;                         // E O NOME POR EXTENSO DO RESPECTIVO MÊS POR MEIO DO ARRAY 2D MesesPorExtenso
}

// INCREMENTA UMA DATA EM UM DIA E VALIDA A NOVA DATA
void Data::IncrementaData()
{
    if ( !FimDoMes( getDia() ) )    // SE NÃO FOR O ÚLTIMO DIA DO MÊS
    {
        dia++;                      // INCREMENTA UM DIA
    }
    else                            // SENÃO SE ESTIVERMOS NO ÚLTIMO DIA DO MÊS...
    {
        if ( getMes() <= 11 )       // ...E O MÊS ATUAL NÃO FOR O MÊS 12 (ÚLTIMO MÊS DO ANO)
        {
            mes++;                  // VIRAMOS O MÊS INCREMENTANDO A VARIÁVEL mes
            dia = 1;                // E ATUALIZAMOS A VARIÁVEL dia PARA O PRIMEIRO DIA DO MES
        }
        else                        // ... E SE ESTIVERMOS NO ÚLTIMO MÊS DO ANO
        {
            ano++;                  // VIRAMOS O ANO INCREMENTANDO A VARIÁVEL ano
            mes = dia = 1;          // E ATUALIZAMOS O DIA E O MÊS PARA O PRIMEIRO DIA DO PRIMEIRO MÊS
        }
    }
}

// DECREMENTA UMA DATA EM UM DIA E VALIDA A NOVA DATA
void Data::DecrementaData()
{
    if ( getDia() > 1 )             // SE NÃO FOR O PRIMEIRO DIA DO MÊS
    {
        dia--;                      // DECREMENTA UM DIA
    }
    else                            // SENÃO SE ESTIVERMOS NO PRIMEIRO DIA DO MÊS...
    {
        if ( getDia() <= 1 && getMes() > 1 )                    // ...E O MÊS ATUAL NÃO FOR JANEIRO (MÊS 1)
        {
            mes--;                                              // DECREMENTA UM MÊS

            if ( getMes() == 2 && AnoBissexto( getAno() ) )     // SE ESTIVERMOS NO MÊS 2 (FEVEREIRO) E O ANO ATUAL FOR BISSEXTO
                dia = DiasEmCadaMes[getMes() - 1] + 1;          // O ÚLTIMO DIA DO MÊS DE FEVEREIRO SE TORNA 28 + 1 = 29
            else
                dia = DiasEmCadaMes[getMes() - 1];              // SENÃO O ÚLTIMO DIA DO MÊS É CONFIGURADO DE ACORDO COM A QTDE DE DIAS EM CADA MÊS
        }
        else if ( getDia() <= 1 && getMes() <= 1 )              // ...E O MÊS ATUAL FOR JANEIRO (MÊS 1)
        {
            ano--;                                              // DECREMENTA UM ANO
            mes = 12;                                           // ATUALIZA O MÊS PARA O ÚLTIMO MÊS (MÊS 12) DO NOVO ANO
            dia = DiasEmCadaMes[getMes() - 1];                  // ATUALIZA O DIA PARA O ÚLTIMO DIA DO ÚLTIMO MÊS DO NOVO ANO
        }
    }
}

// ADICIONA OU SUBTRAI DIAS A UMA DATA E VALIDA A NOVA DATA
void Data::AddSubDias( int Dias )
{
    if ( Dias >= 0 )      // SE O NÚMERO DE DIAS A ADICIONAR A DATA FOR MAIOR OU IGUAL A ZERO
    {
        for( int i = 0; i < Dias; i++ ) // INCREMENTA O NÚMERO DE DIAS DA DATA
            IncrementaData();
    }
    else if ( Dias < 0 )  // SENÃO SE O NÚMERO DE DIAS A ADICIONAR A DATA FOR MENOR QUE ZERO
    {
        for( int i = 0; i > Dias; i-- ) // DECREMENTA O NÚMERO DE DIAS DA DATA
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

// RETORNA QUANTOS DIAS SE PASSARAM DE 1/1/0001 ATÉ A DATA ATUAL
//
// ALGORITMO RATA DIE:
//      NESSE ALGORITMO, CADA ANO SE INICIA EM MARÇO E TERMINA EM FEVEREIRO.
//    MARÇO É O MÊS 3 E FEVEREIRO O MÊS 14. ISSO É FEITO PARA SIMPLIFICAR
//    O RELACIONAMENTO ENTRE A QUANTIDADE DE DIAS EM CADA MÊS, FACILITANDO A
//    A CONTAGEM DOS DIAS. 365*ANO + ANO/4 - ANO/100 + ANO/400 FORNECE O NÚMERO
//    DE DIAS ATÉ O COMEÇO DO ANO EM QUESTÃO, INCLUINDO OS DIAS EXTRAS DOS ANOS
//    BISSEXTOS. (153*MES - 457)/5 É UMA APROXIMAÇÃO LINEAR QUE CALCULA O NÚMERO
//    DE DIAS NO MÊS ANTERIOR. SOMAMOS A ESSAS DUAS EXPRESSÕES O DIA DO MÊS ATUAL.
//    SUBTRAÍMOS 306 PARA AJUSTARMOS PARA O CALENDÁRIO GREGORIANO.
//    306 É O NÚMERO DE DIAS ENTRE 01/03 A 31/12.
//
int Data::DiasAteAData( Data &data )
{
    int Ndias;
    int dia = data.getDia();
    int mes = data.getMes();
    int ano = data.getAno();

    // CONVERTE PARA O NOVO CALENDÁRIO
    if ( mes < 3 )      // SE O MÊS ATUAL FOR FEVEREIRO OU JANEIRO
    {
        ano--;          // DECREMENTA O ANO ATUAL
        mes += 12;      // E SOMA 12 MESES AO MÊS ATUAL
    }                   // NOVO MÊS = 13 (NOVO JAN) OU 14(NOVO FEV)

    Ndias = 365*ano + ano/4 - ano/100 + ano/400 + (153*mes - 457)/5 + dia - 306;

    return Ndias;
}


// RETORNA O NÚMERO DE DIAS ENTRE DUAS DATAS
int Data::DiasEntreDatas( Data &Data1, Data &Data2 )
{                       // UTILIZA A FUNÇÃO DiasAteAData() PARA RETORNAR O NÚMERO DE DIAS...
    int Numero_dias;    // QUE SE PASSARAM DE 1/1/0001 ATÉ CADA UMA DAS DATAS
                        // O NÚMERO DE DIAS ENTRE ESSAS DATAS É ENTÃO A DIFERENÇA ENTRE
    Numero_dias = DiasAteAData( Data1 ) - DiasAteAData( Data2 ); // ESSES DOIS VALORES

    if ( Numero_dias < 0 )              // GARANTE QUE O NÚMERO DE DIAS RETORNADOS SEJA POSITIVO
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

// SOBRECARREGA O OPERADOR DE IGUALDADE == (VERIFICA SE DUAS DATAS SÃO IGUAIS)
bool Data::operator==( const Data &Direita ) const
{
    if ( (dia == Direita.dia) && (mes == Direita.mes) && (ano == Direita.ano) )
        return true;
    else
        return false;
}

// SOBRECARREGA O OPERADOR < (VERIFICA SE UMA DATA É MENOR QUE A OUTRA)
bool Data::operator<( const Data &Direita ) const
{
    bool result = false;

    if ( ano < Direita.ano )            // INICIALMENTE TESTAMOS SE O ESQUERDA.ANO < DIREITA.ANO
    {
        result = true;                  // SE SIM, RETORNA VERDADEIRO
    }
    else if ( ano == Direita.ano )      // SENÃO SE ESQUERDA.ANO FOR IGUAL A DIREITA.ANO...
    {                                   // ...NÃO CONCLUÍMOS NADA, DEVEMOS TESTAR O MÊS DE CADA DATA
        if( mes < Direita.mes )         // ENTÃO SE ESQUERDA.MÊS < DIREITA.MÊS
        {
            result = true;              // RETORNA VERDADEIRO
        }
        else if ( mes == Direita.mes )  // SENÃO, SE ALÉM DOS ANOS, OS MESES FOREM IGUAIS...
        {                               // ...TAMBÉM NÃO CONCLUÍMOS NADA, DEVEMOS TESTAR OS DIAS AGORA
            if ( dia < Direita.dia )    // ENTÃO SE ESQUERDA.DIA < DIREITA.DIA
                result = true;          // RETORNA VERDADEIRO
            else
                result = false;         // SENÃO RETORNA FALSO
        }
    }
    else if ( ano > Direita.ano )       // POR FIM, SE ESQUERDA.ANO FOR MAIOR QUE DIREITA.ANO
    {
        result = false;                 // RETORNA FALSO: ESQUERDA.DATA NÃO É MENOR QUE DIREITA.DATA
    }

    return result;
}

// SOBRECARREGA O OPERADOR > (VERIFICA SE UMA DATA É MAIOR QUE A OUTRA)
bool Data::operator>( const Data &Direita ) const
{
    bool result = false;

    if ( ano > Direita.ano )            // INICIALMENTE TESTAMOS SE O ESQUERDA.ANO > DIREITA.ANO
    {
        result = true;                  // SE SIM, RETORNA VERDADEIRO
    }
    else if ( ano == Direita.ano )      // SENÃO SE ESQUERDA.ANO FOR IGUAL A DIREITA.ANO...
    {                                   // ...NÃO CONCLUÍMOS NADA, DEVEMOS TESTAR O MÊS DE CADA DATA
        if( mes > Direita.mes )         // ENTÃO SE ESQUERDA.MÊS > DIREITA.MÊS
        {
            result = true;              // RETORNA VERDADEIRO
        }
        else if ( mes == Direita.mes )  // SENÃO, SE ALÉM DOS ANOS, OS MESES FOREM IGUAIS...
        {                               // ...TAMBÉM NÃO CONCLUÍMOS NADA, DEVEMOS TESTAR OS DIAS DE CADA DATA
            if ( dia > Direita.dia )    // ENTÃO SE ESQUERDA.DIA > DIREITA.DIA
                result = true;          // RETORNA VERDADEIRO
            else
                result = false;         // SENÃO RETORNA FALSO
        }
    }
    else if ( ano < Direita.ano )       // POR FIM, SE ESQUERDA.ANO FOR MENOR QUE DIREITA.ANO
    {
        result = false;                 // RETORNA FALSO: ESQUERDA.DATA NÃO É MAIOR QUE DIREITA.DATA
    }

    return result;
}

// SOBRECARREGA O OPERADOR DE ATRIBUIÇÃO = (ATRIBUIÇÃO ENTRE DATAS)
const Data &Data::operator=( const Data &Direita )
{                       // SIMPLESMENTE ATRIBUÍMOS CADA MENBRO A DIREITA AO SEU RESPECTIVO MEMBRO A ESQUERDA
    dia = Direita.dia;
    mes = Direita.mes;
    ano = Direita.ano;
    formato = Direita.formato;
    separador = Direita.separador;
    return *this;
}

// SOBRECARREGA O OPERADOR DE SAÍDA <<: FORNECENDO A DATA POR EXTENSO
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
