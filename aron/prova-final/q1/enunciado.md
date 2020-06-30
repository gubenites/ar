% Sistemas Hardware-Software
% Igor Montagner


## Questão 1 (2,0)

Implementamos uma pilha no arquivo `stack.c` e gostaríamos de verificar se nossa implementação está bem feita. Vimos que isso pode ser feito usando o programa `valgrind`. Use-o para

### Parte 1

Rode seu programa com `valgrind` e responda:

* Quantos erros de acesso a memória são detectados?

Foram detectados 10 erros.

* Para cada erro, escreva abaixo em qual linha ele ocorre e se o erro é de leitura ou escrita.

Erro número 1:
- Linha 26 no arquivo stack.c. Foi executado na função main pela função stack_push na linha 39.
- Erro de escrita inválida.

Erro número 2:
- Linha 26 no arquivo stack.c. Foi executado na função main pela função stack_push na linha 40.
- Erro de escrita inválida.

Erro número 3:
- Linha 26 no arquivo stack.c. Foi executado na função main pela função stack_push na linha 41.
- Erro de escrita inválida.

Erro número 4:
- Linha 26 no arquivo stack.c. Foi executado na função main pela função stack_push na linha 42.
- Erro de escrita inválida.

Erros números 5, 6, 7, 8, 9:
- Linha 32 no arquivo stack.c. Foi  está sendo executado na função main pela função stack_pop na linha 44.
- Erro de leitura inválida.

Erro número 10:
- Erro de memória não desalocada depois de ser utilizada.

* O programa libera toda a memória que aloca? Se não, indique onde é feito o `malloc` que não houve `free`.

O programa aloca memória para o data do struct mas não o libera depois com o free. o malloc foi feito na linha 11.

### Parte 2

Conserte o código de `stack.c`. Você **não** pode modificar a função `main`. Se a pilha ficar em um estado inválido seu programa deverá mostrar uma mensagem de erro e assumir que os elementos não existentes são 0.

Suas modificações deverão ser baseadas nas respostas acima. Para cada problema descrito na parte 1 escreva abaixo o que foi feito para consertá-lo.

- Para consertar o código foi utilizado a função stack_full para checar se a pilha está cheia. No caso do pop foi realizado o check se a pilha estava no seu ínicio.