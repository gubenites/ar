% Sistemas Hardware-Software
% Igor Montagner

Esta prova tem algumas regras específicas sobre o código de vocês. Elas falam tanto de qualidade de software quanto do domínio de vocês do código que escreveram.

1. Colar código encontrado no StackOverflow implica em 0 na questão.

2. Toda função não apresentada em aula deverá ser acompanhada de um link para documentação nos seguintes site

* http://cplusplus.com/reference/clibrary/
* https://en.cppreference.com/w/c/header

Relativo a qualidade de software, os conceitos B e A são reservados para programas em C bem escritos. Logo, se seu programa tiver os seguintes problemas sua nota máxima na questão em que ocorrem será C+ (60%).

* Erros de memória no `valgrind.
* Memória não liberada após o fim do programa.
* Warnings durante a compilação.
* Variáveis globais sem motivo.

Todos programas serão compilados com as flags

```
-g -Og -Wall -pedantic -Wno-unused-result -std=gnu99
```

Finalmente, esta prova é individual. São permitidas consultas ao material e a internet, porém qualquer contato com outras pessoas (sejam alunos ou terceiros) será considerado violação do código de ética do Insper.
