% Sistemas Hardware-Software
% Igor Montagner

## Questão 2 (2,0)

O programa *varias_tarefas.c* é formado por 4 tarefas (funções `tarefaA`, `tarefaB`, `tarefaC` e `tarefaD`). Os prints de cada tarefa indicam quais são as interdependências entre as tarefas.

Você deverá lançar todas as threads ao mesmo tempo e esperar por elas na função `main`. Toda a sincronização deverá ser feita dentro das funções de cada tarefa.

1. Quantos semáforos são usados? Quais seus nomes e valores iniciais?

São usados 3 semafóros.

O semaphore1 é utlizado com valor inicial igual a zero.
O semaphore2 é utlizado com valor inicial igual a zero.
O semaphore3 é utlizado com valor inicial igual a zero.

2. Para cada semáforo acima, descreva seu uso no programa.

O semaphore1 é utlizado para destravar a tarefa D depois do fim da tarefa A.
O semaphore2 é utilizado para destravar a tarefa C depois que essa já rodou sua primeira parte.
O semaphore3 é utilzaido para destravar a tarefa B depos quie a D já terminou.

<div class="alert">
Suas respostas acima deverão estar condizentes com o programa entregue.
</div>

<div class="alert">
Passar dados para a funções rodadas nas threads é parte do exercício. Se seu programa só usar variáveis globais sua nota máxima será 1,5.
</div>
