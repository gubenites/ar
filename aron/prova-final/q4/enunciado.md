% Sistemas Hardware-Software
% Igor Montagner

## Questão 4 (4,0)

Estamos produzindo um programa (arquivo *hw-info.c*) que recebe dados de um hardware conectado ao USB. Porém, os drivers são muito ruins e crasham toda hora nosso programa. As saídas de nosso programa são, frequentemente, como a mostrada abaixo.

```
Hardware inicializado
Steps: 20
Steps: 96
Steps: 9
Steps: 56
Segmentation fault
```

Gostaríamos que toda vez que o driver crashar o programa detecte este problema e reinicie a coleta de dados. A saída do programa seria, então, como abaixo:

```
Hardware inicializado
Steps: 20
Steps: 96
Steps: 9
Steps: 56
Erro detectado! Reinicializando o processo de coleta
Hardware inicializado
Steps: 79
Steps: 93
Steps: 54
Steps: 18
Steps: 97
Erro detectado! Reinicializando o processo de coleta
......
```

O programa prossegue infinitamente.

<div class="alert"> Nosso programa simula o firmware com as funções `hw_init`, `hw_get_steps` e `hw_shutdown`. Elas não devem ser mudadas de maneira alguma. </div>

**Conceito D**: Um colega seu sugeriu criar uma *thread* para rodar o código que faz esta coleta. Assim, disse ele, o main estaria protegido dos erros que ocorrem na thread e você poderia reinicializar esta thread toda vez que ela gerasse erro. Você concorda com seu colega? Se ele estiver certo, explique como você implementaria a solução proposta. Se estiver errado, explique a razão e proponha uma solução para o problema.

A ideia é que o erro que passasse pela thread pararia o programa pai não seria possível prosseguir. Seria um erro que pararia o programa.

**Conceito C**: Implemente a solução proposta acima. Seu arquivo deverá se chamar *hw-info-C.c*.

<div class="alert"> Se a solução descrita no item **D** não for a mesma que a implementada, o valor da questão acima se torna 0 </div>

Um segundo problema foi percebido agora que, com sua solução, o programa parou de dar erros. Quando terminamos o programa com Ctrl+C o hardware continua ligado!

**Conceito C+**: Como você faria para desligar o hardware quando seu programa recebe Ctrl+C? Descreva uma solução para este problema e aponte quais mudanças seriam necessárias para que o seu programa do nível anterior se comporte dessa maneira.

**Conceito B+**: Implemente a solução descrita acima. Seu arquivo deverá se chamar *hw-info-B.c*

**Conceito A+**: Modifique seu programa acima para que ele só possa ser finalizado usando Ctrl+C. **Dica**: `man sigprocmask`.

