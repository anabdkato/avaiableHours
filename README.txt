O PROJETO

O projeto consiste em uma tela onde o usuário insere o horário desejado.

A partir do horario inserido a função avaiableHours lê o arquivo 'restaurant_hours.csv' e compara os dados
inseridos pelo usuário com a segunda coluna do arquivo, vendo quais restaurantes estão abertos naquele
horário.

Ao rodar o projeto, deve aparecer uma tela com a mensagem "Veja os restaurantes abertos", e um botão no canto
inferior direito com a mensagem "Adicionar horarios". Ao clicar no botão o usuário verá abrir uma caixa para 
insersão do horário, sendo o primeiro espaço destinado às horas, e o segundo aos minutos. Ao completar os
espaços o usuário deverá apertar o botão de "OK". Feito isso, a tela que antes exibia a mensagem "Veja os restaurantes 
abertos", passará a exibir uma lista com os nomes dos restaurantes abertos no horário pelo usuário inserido.
O usuário pode inserir novos dados de hora quantas vezes desejar seguindo o mesmo procedimento.

AS ESCOLHAS

Por ter pouca experiência com Qt e qml o projeto foi baseado no exemplo de contaclist (em 
Qt\Examples\Qt-5.15.0\quickcontrols2\contactlist) para aproveitar a parte gráfica de interação com
entrada de usuário e também a integração de qml com c++.

As alterações feitas nessa parte consistiram em alterar a tela para que antes apenas exibisse uma mensagem
e ao fim exibisse a lista. Além disso foram feitas alterações na parte de entrada de dados fornecidos
pelo usuário. Depois das alterações o usuário insere duas informações: a hora e os minutos.
Foi acrescida também uma função para validar que o horário é uma entrada válida, sendo as horas um valor
entre 1 e 24, e os minutos entre 0 e 59. Caso o usuário entre com um dado inválido a caixa de diálogo é limpa
e pede novamente para que o usuário entre com os dados. Caso contrário, a tela é limpa e populada com os restaurantes
abertos.

A parte de manipulação com arquivo foi também baseada em um exemplo da internet, do link:
http://web.archive.org/web/20150227025348/http://developer.nokia.com/community/wiki/Reading_and_writing_files_in_QML

A função final, avaiableHours, teve como base principal a função de read, para ler cada linha do arquivo. Porém
foi acrescida a manipulação e comparação dos dados de cada linha.
Os dados de hora e minuto, tanto os entrados pelo usuário quanto os lidos do arquivo, foram usadas dentro da função como um único 
número inteiro para facilitar a comparação.

Os testes unitários foram feitos à partir da documentação em https://doc.qt.io/qt-5/qttestlib-tutorial1-example.html


OBS.:

Pelo fato de o projeto só ter tomado uma forma mais clara no final, o repositório estará em um commit único