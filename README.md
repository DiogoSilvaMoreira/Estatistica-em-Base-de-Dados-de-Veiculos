 Projeto de Manipulação de Dados de Veículos 
---

---

Objetivo
---
O objetivo deste projeto é adquirir conhecimentos sobre a manipulação de valores em variáveis simples com estruturas de controle, além de construir estatísticas a partir de dados lidos de um arquivo-texto.

---

Descrição
---
O aplicativo desenvolvido no projeto realiza a leitura de dados de veículos armazenados em um arquivo-texto e atualiza variáveis para calcular e apresentar as estatísticas solicitadas. Cada linha do arquivo contém informações sobre um veículo, incluindo modelo, marca, tipo, ano, quilometragem, potência do motor, combustível, câmbio, direção, cor, portas, placa e valor do veículo.

Após a leitura do arquivo, o aplicativo apresentará as informações solicitadas de forma clara e objetiva, incluindo:

    Porcentagem de veículos nas categorias de tipo;
    Porcentagem de veículos com câmbio automático e direção hidráulica;
    Veículo mais barato com motor 1.0, incluindo placa, valor e valor da prestação do financiamento em 48 meses com taxa de juros atual;
    Veículo mais caro com direção hidráulica e combustível flex, incluindo placa, valor e valor estimado do seguro;
    Quantidade e média de quilometragem dos veículos com 5 anos ou mais (a partir de 2018).

Arquivo de Entrada:

O arquivo de entrada, chamado BD_veiculos.txt, deve conter um número indeterminado de linhas, com cada linha representando um veículo. Cada linha contém 10 campos:

    Modelo
    Marca
    Tipo
    Ano
    Quilometragem
    Potência do motor
    Combustível
    Câmbio
    Direção
    Cor
    Portas
    Placa
    Valor do veículo

A última linha contém a palavra FIM no campo do modelo e não será considerada nos cálculos.

                               Exemplo de linha de dados
--------- Fusca,Volkswagen,sedan,1975,150000,1.3,gasolina,manual,mecânica,azul,2,ABC1234,15000 ---------------

---

Requisitos
---

O aplicativo deverá apresentar as seguintes informações após a leitura do arquivo:

    Porcentagens de veículos nas categorias de tipo: Percentual de veículos em cada categoria (ex: sedan, SUV, hatch, etc.).
    Porcentagem de veículos com câmbio automático e direção hidráulica: Percentual de veículos com essas características.
    Veículo mais barato entre os com motor 1.0:
        Placa
        Valor
        Valor da prestação do financiamento em 48 meses (com taxa de juros atual).
    Veículo mais caro com direção hidráulica e combustível flex:
        Placa
        Valor
        Valor estimado do seguro (calculado como uma porcentagem do valor do veículo).
    Quantidade e média de quilometragem dos veículos com 5 anos ou mais (a partir de 2018): Estatísticas sobre esses veículos.

Tecnologias Utilizadas

    Linguagem de programação: C++

Como Executar

    Clone o repositório.
    Adicione o arquivo BD_veiculos.txt no mesmo diretório do projeto.
    Execute o código para gerar as estatísticas.
---

