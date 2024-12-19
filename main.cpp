/*
 * File:   main.cpp
 * Author: Diogo da Silva Moreira - 2023.1.08.003
 *
 * Created on 23 de maio de 2023, 17:07
 */


//Incluindo as Biobliotecas
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <math.h>

// Definição das cores
#define AZUL "\e[1;34m"
#define AMARELO "\e[1;33m"
#define VERDE "\e[0;32m"
#define RESET "\e[0m"

using namespace std;

int main(int argc, char** argv) {

    // Declarando as variaveis
    string Modelo, Tipo_Cambio, Tipo_Direcao, Tipo_Combustivel, Placa_Mais_Caro, Placa_Mais_Barato, Tipo_De_Carro, Placa_AUX;
    // usando o string para identificar uma sequência de caracteres.
    int cont_Automatico_Hidraulico = 0;
    int cont_Sedan = 0, cont_Hatch =0, cont_Pick_Up = 0, cont_SUV = 0, cont_Passeio = 0, cont_Van = 0, cont_Total = 0, Ano_Carro = 0;
    int Quantidade_Carro_Velho = 0, Km_AUX = 0, Soma_Km_Carro_Velho = 0;
    int Valor_Mais_Barato = 1000000000, Valor_Mais_Caro = -1;
    // usando int para armazenar valores numéricos inteiros.
    float Potencia_Do_Motor = 0, Valor_Do_Carro = 0;
    float Valor_Parcela_Financiamento = 0;
    // usando float para armazenar valores numéricos fracionários, como números decimais.


    // Abertura do arquivo
    ifstream arquivo ("BD_Veiculos.txt");
    // ifstream para leitura de arquivos.
    if (!arquivo.is_open()) {
        cerr << "Não foi possivel abrir o arquivo!" << endl;
        return 1;
    }
    // 

    arquivo >> Modelo;
    while (Modelo != "FIM") {
    // while para  repetir um bloco de código enquanto uma determinada condição for verdadeira.

        // Obtendo os valores
        arquivo >> Tipo_De_Carro;
        arquivo >> Tipo_De_Carro;
        arquivo >> Ano_Carro;
        arquivo >> Km_AUX;
        arquivo >> Potencia_Do_Motor;
        arquivo >> Tipo_Combustivel;
        arquivo >> Tipo_Cambio;
        arquivo >> Tipo_Direcao;
        arquivo >> Placa_AUX;
        arquivo >> Placa_AUX;
        arquivo >> Placa_AUX;
        arquivo >> Valor_Do_Carro;
        cont_Total++;

        // Os tipos de cada veiculo
        if (Tipo_De_Carro == "Van") {
            cont_Van++;
        } else if (Tipo_De_Carro == "Hatch") {
            cont_Hatch++;
        } else if (Tipo_De_Carro == "Pick-up") {
            cont_Pick_Up++;
        } else if (Tipo_De_Carro == "SUV") {
            cont_SUV++;
        } else if (Tipo_De_Carro == "Passeio") {
            cont_Passeio++;
        } else {
            cont_Sedan++;
        }
        //usando else que indica quais instruções o sistema deve processar.

        // Checando o Cambio 
        if ((Tipo_Cambio == "Automático") && (Tipo_Direcao == "Hidráulica")){
            cont_Automatico_Hidraulico++;
        };

        // Placa e valor do veículo mais barato entre os veículos com potência do motor 1.0, e ainda, valor da prestação do financiamento em 48 meses        
        if (Potencia_Do_Motor == 1.0) {
            if (Valor_Do_Carro < Valor_Mais_Barato) {
                Valor_Mais_Barato = Valor_Do_Carro;
                Placa_Mais_Barato = Placa_AUX;
                // Banco do Brasil ---> 1,95 (a.m) - 26,03 (a.a)
                Valor_Parcela_Financiamento = (Valor_Do_Carro * pow((1 + 0.0195), 48)) / 48;
            }
        }

        // Placa e valor do veiculo mais caro com direção hidraúlica e combusti­vel flex e o valor do seguro
        if ((Tipo_Direcao == "Hidráulica") && (Tipo_Combustivel == "Flex") && (Valor_Do_Carro > Valor_Mais_Caro)){
            Valor_Mais_Caro = Valor_Do_Carro;
            Placa_Mais_Caro = Placa_AUX;
        }

        // Veículos com 5 anos ou mais (2018).
        if (Ano_Carro <= 2018) {
            Quantidade_Carro_Velho++;
            Soma_Km_Carro_Velho = Soma_Km_Carro_Velho + Km_AUX;
        }

        arquivo >> Modelo;
    }

    // Impressão das informações solicitadas
    cout << "\n\n* --------------------------------------------- *" << endl;
    cout << "*" << AMARELO << "\tPorcentagem de veículos por tipo:" << RESET << "\t*" << endl;
    cout << "*\t\t" << AZUL << "Van: " << RESET << ((float)cont_Van/cont_Total) * 100 << "%" << "\t\t\t*" << endl;
    cout << "*\t\t" << AZUL << "Hatch: " << RESET << ((float)cont_Hatch/cont_Total) * 100 << "%" << "\t\t\t*" << endl;
    cout << "*\t\t" << AZUL << "Pick_up: " << RESET << ((float)cont_Pick_Up/cont_Total) * 100 << "%" << "\t\t\t*" << endl;
    cout << "*\t\t" << AZUL << "SUV: " << RESET << ((float)cont_SUV/cont_Total) * 100 << "%" << "\t\t\t*" << endl;
    cout << "*\t\t" << AZUL << "Passeio: " << RESET << ((float)cont_Passeio/cont_Total) * 100 << "%" << "\t\t\t*" << endl;
    cout << "*\t\t" << AZUL << "Sedan: " << RESET << ((float)cont_Sedan/cont_Total) * 100 << "%" << "\t\t\t*" << endl;
    cout << "* --------------------------------------------- *" << endl;
    cout << "*    " << AMARELO << "Porcentagem de veículos com câmbio\t\t" << RESET << "*\n*    " << AMARELO << "automático e direção hidráulica: ";
    cout << AZUL << ((float)cont_Automatico_Hidraulico/cont_Total) * 100 << "%" << RESET << "    *" << endl;
    cout << "* --------------------------------------------- *" << endl;
    cout << "*\t" << AMARELO << "Placa e valor do veículo mais barato    " << RESET << "*\n*\t" << AMARELO << "com potência do motor 1.0: " << RESET << "\t\t*" << endl;
    cout << "*\t\t" << AZUL << "Placa: " << RESET << Placa_Mais_Barato << "\t\t\t*" << endl;
    cout << "*\t\t" << AZUL << "Valor: " << RESET << Valor_Mais_Barato << "\t\t\t*" << endl;
    cout << "* --------------------------------------------- *" << endl;
    cout << "*\t" << AMARELO << "Valor da prestação do financiamento     " << RESET << "*\n*\t" << AMARELO << "em 48 meses [1.95 a.m.]: " << AZUL << Valor_Parcela_Financiamento << RESET << "\t*" << endl;
    cout << "* --------------------------------------------- *" << endl;
    cout << "*\t" << AMARELO << "Placa e valor do veículo mais caro      " << RESET << "*\n*\t" << AMARELO << "com direção hidráulica e combustível    " << RESET << "*\n*\t" << AMARELO << "flex: \t\t\t\t\t" << RESET "*" << endl;
    cout << "*\t\t" << AZUL << "Placa: " << RESET << Placa_Mais_Caro << RESET << "\t\t\t*" << endl;
    cout << "*\t\t" << AZUL << "Valor: " << RESET << Valor_Mais_Caro << RESET << "\t\t\t*" << endl;
    cout << "* --------------------------------------------- *" << endl;
    cout << "*\t" << AMARELO << "Valor do seguro estimado (5% sobre o    " << RESET << "*\n*\t" << AMARELO << "valor do veículo): " << AZUL << Valor_Mais_Caro * 0.05 << RESET << "\t\t*" << endl;
    cout << "* --------------------------------------------- *" << endl;
    cout << "*\t" << AMARELO << "Quantidade de veículos com 5 anos ou    " << RESET << "*\n*\t" << AMARELO << "mais (2018): " << AZUL << Quantidade_Carro_Velho << RESET "\t\t\t\t*" << endl;
    cout << "*\t" << AMARELO << "Média de quilometragem dos veículos     " << RESET << "*\n*\t" << AMARELO << "com 5 anos ou mais: " << AZUL << Soma_Km_Carro_Velho/Quantidade_Carro_Velho << RESET << "\t\t*" << endl;
    cout << "* --------------------------------------------- *" << endl;
    return 0;
}