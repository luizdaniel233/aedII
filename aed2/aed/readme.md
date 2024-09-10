Explicações e Melhorias
Correção de Nomes e Tipos:

Corrigi o nome da variável ISDN para isbn, que é mais apropriado para identificar um livro pelo ISBN.
Espaços em Branco:

Adicionei espaços antes dos especificadores de formato em scanf para garantir que espaços em branco sejam ignorados e que a leitura funcione corretamente.
Separadores:

Adicionei a leitura e impressão dos separadores, mesmo que não sejam usados além da leitura. Isso pode ajudar na depuração, mostrando que o programa está processando os separadores corretamente.
Comentários:

Adicionei comentários para melhorar a clareza do código.
Teste do Código
Para testar o código, você pode fornecer uma linha de entrada como a seguinte:

mathematica
Copiar código
ADD;1234567890123;O Grande Livro;Autor Famoso;2024
Isso deve produzir a seguinte saída:

makefile
Copiar código
CMD: ADD
ISBN: 1234567890123
Título: O Grande Livro
Autor: Autor Famoso
Ano: 2024
Este código é útil para verificar se os campos estão sendo lidos corretamente. Uma vez que a leitura esteja funcionando corretamente, você pode integrar esta lógica ao seu sistema de gerenciamento de biblioteca, se necessário.